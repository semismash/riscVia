# ============================================================================
#  Branch-predictor regression test (assemble with: make asm)
#
#  Six sections, each self-checking. Every passing section adds 1 to
#     x29 (t4)   expected 6   (0x00000006)  -> all sections passed
#     (also copied to x10 (a0) right before the ECALL)
#
#   A  long backward loop (100 iters)       predictor warm-up, then steady taken;
#                                           the final exit is a predicted-taken
#                                           branch that is NOT taken (rollback path)
#   B  alternating taken / not-taken        local-history behaviour
#   C  nested loops (8 x 12)                loop exit mispredicted 8 times
#   D  always-taken forward branch over     wrong-path illegal words must be
#      illegal words (40 iters)             flushed, never HALT
#   E  6 taken branches whose PCs share one BTB set (1 KB apart), 30 rounds
#                                           PLRU replacement + BTB set thrashing
#   G  store loop + load loop               load-use stall straight into a branch,
#                                           store with forwarded data, JAL in loop
#
#  The ECALL at the end stops the CPU. Scratch: t0, s0-s8; t1/t2 belong to E.
#  NOTE: the simulation prints x1..MAX_GPR; x10 (a0) shows with the default 20.
# ============================================================================

    .section .text
    .globl _start

_start:
# ----------------------------------------------------------------------------
#  A: 100-iteration backward loop
# ----------------------------------------------------------------------------
    addi s2, x0, 100
    addi s3, x0, 0
    addi s4, x0, 0
a_loop:
    addi s3, s3, 1
    addi s4, s4, 3
    bne  s3, s2, a_loop              # taken 99x, falls through once
    addi t0, x0, 300
    bne  s4, t0, a_end               # skip the score if the sum is wrong
    addi t4, t4, 1
a_end:

# ----------------------------------------------------------------------------
#  B: alternating branch (taken on even counter, not taken on odd)
# ----------------------------------------------------------------------------
    addi s2, x0, 64
    addi s3, x0, 0
    addi s5, x0, 0
b_loop:
    addi s3, s3, 1
    andi t0, s3, 1
    beq  t0, x0, b_skip              # taken when s3 is even
    addi s5, s5, 1                   # counts the odd values -> 32
b_skip:
    nop                              # keeps the two branches >= 3 fetches apart
    nop
    bne  s3, s2, b_loop              # taken 63x
    addi t0, x0, 32
    bne  s5, t0, b_end
    addi t4, t4, 1
b_end:

# ----------------------------------------------------------------------------
#  C: nested loops, 8 outer x 12 inner
# ----------------------------------------------------------------------------
    addi s2, x0, 8
    addi s6, x0, 0
    addi s7, x0, 0
c_outer:
    addi s3, x0, 0
    addi s8, x0, 12
c_inner:
    addi s3, s3, 1
    addi s7, s7, 1
    bne  s3, s8, c_inner             # taken 11x per outer round, then exits
    addi s6, s6, 1
    bne  s6, s2, c_outer             # taken 7x
    addi t0, x0, 96
    bne  s7, t0, c_end
    addi t4, t4, 1
c_end:

# ----------------------------------------------------------------------------
#  D: always-taken forward branch over illegal words (40 iterations)
#     early iterations: predicted not-taken -> the illegal words are fetched
#     on the wrong path and must be flushed without a HALT
#     later iterations: predicted taken -> they are never fetched at all
# ----------------------------------------------------------------------------
    addi s2, x0, 40
    addi s3, x0, 0
d_loop:
    addi s3, s3, 1
    beq  x0, x0, d_skip
    .word 0xFFFFFFFF
    .word 0x00000000
d_skip:
    nop
    nop
    bne  s3, s2, d_loop
    bne  s3, s2, d_end               # never taken here (s3 == s2), just a check
    addi t4, t4, 1
d_end:

# ----------------------------------------------------------------------------
#  E: six always-taken branches whose PCs differ only in the tag bits
#     (blocks 1 KB apart, branch at +4 in each) -> all map to one BTB set and
#     one BHT entry; 6 tags compete for 4 ways
#     t1 = visits (expect 180), t2 = executions of a skipped instruction (expect 0)
# ----------------------------------------------------------------------------
    addi s2, x0, 30
    addi s3, x0, 0
e_loop:
    jal  x0, blk0
e_back:
    addi s3, s3, 1
    bne  s3, s2, e_loop
    addi t0, x0, 180
    bne  t1, t0, e_end
    bne  t2, x0, e_end
    addi t4, t4, 1
e_end:

# ----------------------------------------------------------------------------
#  G: fill an array with a store loop, sum it with a load loop
#     load result feeds a branch on the very next instruction (load-use stall)
# ----------------------------------------------------------------------------
    lui  s0, 0x3                     # s0 = 0x3000 (array base)
    addi s3, s0, 0
    addi s1, x0, 0
    addi s2, x0, 20
g_fill:
    addi s1, s1, 1
    sw   s1, 0(s3)                   # data forwarded from the addi above
    addi s3, s3, 4
    bne  s1, s2, g_fill              # 20 iterations
    sw   x0, 0(s3)                   # terminator
    addi s3, s0, 0
    addi s6, x0, 0
g_read:
    lw   t0, 0(s3)
    beq  t0, x0, g_done              # load-use into a branch; taken only on the terminator
    add  s6, s6, t0
    addi s3, s3, 4
    jal  x0, g_read
g_done:
    addi t0, x0, 210
    bne  s6, t0, g_end
    addi t4, t4, 1
g_end:

    add  a0, t4, x0                  # mirror the score into x10 so it shows with MAX_GPR = 20
    ecall                            # stop here

# ----------------------------------------------------------------------------
#  Blocks for E: each starts on a 1 KB boundary, branch at offset +4
# ----------------------------------------------------------------------------
    .balign 1024
blk0:
    addi t1, t1, 1
    beq  x0, x0, blk0_t
    addi t2, t2, 1                   # must never execute
blk0_t:
    jal  x0, blk1

    .balign 1024
blk1:
    addi t1, t1, 1
    beq  x0, x0, blk1_t
    addi t2, t2, 1
blk1_t:
    jal  x0, blk2

    .balign 1024
blk2:
    addi t1, t1, 1
    beq  x0, x0, blk2_t
    addi t2, t2, 1
blk2_t:
    jal  x0, blk3

    .balign 1024
blk3:
    addi t1, t1, 1
    beq  x0, x0, blk3_t
    addi t2, t2, 1
blk3_t:
    jal  x0, blk4

    .balign 1024
blk4:
    addi t1, t1, 1
    beq  x0, x0, blk4_t
    addi t2, t2, 1
blk4_t:
    jal  x0, blk5

    .balign 1024
blk5:
    addi t1, t1, 1
    beq  x0, x0, blk5_t
    addi t2, t2, 1
blk5_t:
    jal  x0, e_back