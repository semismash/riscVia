# ============================================================================
#  Regression test for the fixed RV32I core  (assemble with: make asm)
#
#  Result registers (read them in the LAST printed cycle of the simulation):
#     x28 (t3) = Test 1 score   expected 4   (JALR forwarding, 4 sub-tests)
#     x29 (t4) = Test 2 score   expected 3   (store address, 3 sub-tests)
#     x30 (t5) = Test 3 score   expected 4   (no false HALT, 4 sub-tests)
#     x31 (t6) = t3+t4+t5       expected 11  (0x0000000b) -> everything passed
#
#  Test 4 (store right after ECALL) is checked outside the registers:
#     * the sim must end with "safe STOP signal", not "HALT"
#     * no WRITE to address 0x3f00 may ever appear in the log
#     * and, of course, no HALT from the 0xFFFFFFFF word placed after the sw
#
#  Test 5 (telemetry) is checked from the metrics printed at the end,
#  see the expected values given alongside this file.
#
#  Registers used as scratch: ra, sp, t0-t2, s0-s3
# ============================================================================

    .section .text
    .globl _start

_start:
    lui  sp, 0x2                     # sp = 0x2000

# ----------------------------------------------------------------------------
#  TEST 1: JALR target must use FORWARDED rs1
#  Each sub-test plants a "wrong" (stale) address in the register right before
#  the real value is produced, so a stale read lands on a *_fail stub, which
#  jumps back to the continuation WITHOUT incrementing the score.
# ----------------------------------------------------------------------------
    # 1A: lw ra / addi sp / ret   (value arrives via MEM/WB forwarding)
    jal  ra, t1_funcA
    addi t3, t3, 1                   # only reached if ret returned here
t1_after_A:

    # 1B: lw ra / ret   (load-use stall directly into JALR)
    jal  ra, t1_funcB
    addi t3, t3, 1
t1_after_B:

    # 1C: target built by the instruction right before jalr (EX/MEM forwarding)
    la   t0, t1_fail_C               # stale value
    la   t0, t1_good_C               # real value, produced immediately before jalr
    jalr x0, 0(t0)
    j    t1_fail_C                   # wrong path, must be flushed, never executed
t1_good_C:
    addi t3, t3, 1
t1_after_C:

    # 1D: same, with one instruction gap (MEM/WB forwarding)
    la   t0, t1_fail_D
    la   t0, t1_good_D
    nop
    jalr x0, 0(t0)
    j    t1_fail_D
t1_good_D:
    addi t3, t3, 1
t1_after_D:

# ----------------------------------------------------------------------------
#  TEST 2: store ADDRESS must use the immediate even when rs2 is forwarded
#  (old core used the forwarded data value as the offset: addr = base + data)
# ----------------------------------------------------------------------------
    lui  s0, 0x2
    addi s0, s0, 0x100               # s0 = 0x2100 (scratch area)

    # 2A: rs2 forwarded from EX/MEM
    addi t0, x0, 0x55
    sw   t0, 8(s0)                   # must land at 0x2108 (old core: 0x2155)
    lw   t1, 8(s0)
    addi t2, x0, 0x55
    bne  t1, t2, t2_skip_A
    addi t4, t4, 1
t2_skip_A:

    # 2B: rs2 forwarded from MEM/WB
    addi t0, x0, 0x66
    nop
    sw   t0, 12(s0)                  # must land at 0x210c
    lw   t1, 12(s0)
    addi t2, x0, 0x66
    bne  t1, t2, t2_skip_B
    addi t4, t4, 1
t2_skip_B:

    # 2C: base from MEM/WB and data from EX/MEM at the same time
    addi s1, s0, 0
    addi t0, x0, 0x77
    sw   t0, 16(s1)                  # must land at 0x2110
    lw   t1, 16(s0)
    addi t2, x0, 0x77
    bne  t1, t2, t2_skip_C
    addi t4, t4, 1
t2_skip_C:

# ----------------------------------------------------------------------------
#  TEST 3: illegal words on a flushed (wrong) path must NOT halt the CPU
#  0xFFFFFFFF and 0x00000000 are illegal instructions, but they are only ever
#  fetched on the wrong path of a taken jump/branch here.
# ----------------------------------------------------------------------------
    addi s2, x0, 3
    addi s3, x0, 0
t3_loop:
    addi s3, s3, 1
    beq  s3, s2, t3_done             # taken on the 3rd iteration
    j    t3_loop                     # taken on iterations 1 and 2
    .word 0xFFFFFFFF                 # wrong path after the j
    .word 0x00000000
t3_done:
    addi t5, t5, 1                   # 3A: loop with j-over-illegal survived

    beq  x0, x0, t3_skip1            # always taken
    .word 0xFFFFFFFF
    .word 0x00000000
t3_skip1:
    addi t5, t5, 1                   # 3B: taken branch over illegal words

    la   t0, t3_skip2
    jalr x0, 0(t0)
    .word 0xFFFFFFFF
    .word 0x00000000
t3_skip2:
    addi t5, t5, 1                   # 3C: JALR over illegal words

    jal  x0, t3_skip3
    .word 0xFFFFFFFF
t3_skip3:
    addi t5, t5, 1                   # 3D: JAL over an illegal word

# ----------------------------------------------------------------------------
#  TEST 4: nothing after ECALL may take effect (this must be the LAST thing
#  that executes, ECALL stops the CPU)
# ----------------------------------------------------------------------------
    add  t6, t3, t4
    add  t6, t6, t5                  # t6 = 4 + 3 + 4 = 11 if all passed
    lui  s0, 0x4
    addi s0, s0, -256                # s0 = 0x3f00 (watch address)
    lui  s1, 0xBADF
    addi s1, s1, 13                  # s1 = 0x0badf00d
    ecall
    sw   s1, 0(s0)                   # must NOT execute (no WRITE to 0x3f00 in the log)
    .word 0xFFFFFFFF                 # must NOT cause a HALT after the STOP

# ----------------------------------------------------------------------------
#  Helpers (only reached through the tests above)
# ----------------------------------------------------------------------------
t1_funcA:
    addi sp, sp, -16
    sw   ra, 0(sp)                   # save the real return address
    la   ra, t1_fail_A               # clobber ra with the "stale" value
    lw   ra, 0(sp)                   # reload the real one
    addi sp, sp, 16
    ret                              # jalr x0, 0(ra)
t1_fail_A:
    j    t1_after_A

t1_funcB:
    addi sp, sp, -16
    sw   ra, 0(sp)
    la   ra, t1_fail_B
    addi sp, sp, 16
    lw   ra, -16(sp)
    ret                              # load-use straight into JALR
t1_fail_B:
    j    t1_after_B

t1_fail_C:
    j    t1_after_C

t1_fail_D:
    j    t1_after_D