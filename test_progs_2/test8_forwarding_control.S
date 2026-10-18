# =============================================================================
# Test 8: General ALU / load-store / forwarding correctness (control test)
#
# Metric: baseline pipeline sanity check, deliberately ISOLATED from branch
# prediction (the block below is fully unrolled via .rept -- no loop branch
# inside the hot path at all). If this test fails but the branch-prediction
# tests also show wrong final register values, the bug is in the base
# pipeline/forwarding, not the predictor. If this test passes but others
# don't, the bug is specific to prediction/recovery.
#
# Each repetition exercises:
#   - EX-EX forwarding: three back-to-back ALU ops with zero-cycle RAW
#     hazards (each instruction consumes the previous one's result
#     immediately), including a self-doubling op that causes genuine
#     32-bit unsigned overflow/wraparound over repeated iterations --
#     also checks overflow is handled correctly, not just forwarding.
#   - Load-use hazard + MEM-EX forwarding: a load immediately followed by
#     a dependent ALU op (the classic case that needs a stall even with
#     full forwarding, since data isn't ready until the MEM stage).
#   - Store-to-load same-address hazard: a store immediately followed by a
#     load from the same address, which must observe the just-stored
#     value (via store-to-load forwarding or guaranteed memory ordering).
#
# Expected values (verified by simulation):
#   s1 (accumulated scratch-word reads) = sum(1..100)            = 5050
#   s2 (2*(s2+2) repeated 100x, 32-bit wraparound) = 0xFFFFFFFC  = -4
#
# NOTE: requires a valid stack pointer, same caveat as Test 5 -- set
# STACK_TOP to a real writable RAM address in your memory map.
#
# Expected result: a0 = 1 (pass) if s1 == 5050 and s2 == -4 (0xFFFFFFFC).
# =============================================================================

.section .text
.globl _start

.equ STACK_TOP, 0x00002000     # TODO: set to a valid RAM address for your memory map

_start:
    li   sp, STACK_TOP
    addi sp, sp, -4            # reserve one scratch word on the stack
    mv   s0, sp                  # s0 = address of scratch word
    sw   zero, 0(s0)              # initialize scratch word to 0

    li   s1, 0                      # accumulator: store/load-forwarding check
    li   s2, 0                       # accumulator: pure EX-EX ALU forwarding check

    .rept 100
    # --- EX-EX forwarding: back-to-back ALU ops, zero-cycle RAW hazards ---
    addi s2, s2, 1
    addi s2, s2, 1                     # consumes previous result immediately
    add  s2, s2, s2                      # consumes previous result immediately (doubling)

    # --- load-use hazard + MEM-EX forwarding ---
    lw   t0, 0(s0)                         # load current scratch value
    addi t0, t0, 1                           # load-use hazard: needed the very next cycle
    sw   t0, 0(s0)                             # store updated value back

    # --- store-to-load hazard: same address, immediate reload ---
    lw   t1, 0(s0)                               # must see the value just stored above
    add  s1, s1, t1                                # MEM-EX forward straight into ALU
    .endr

    li   t2, 5050
    bne  s1, t2, fail8
    li   t3, -4
    bne  s2, t3, fail8
    li   a0, 1                                        # pass
    j    done8
fail8:
    li   a0, 0                                         # fail
done8:
    ebreak
