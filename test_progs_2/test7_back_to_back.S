# =============================================================================
# Test 7: Back-to-back branches (tight spacing + forwarding-into-branch)
#
# Metric: general pipeline correctness under forwarding + prediction
# interacting, specifically:
#   - 8 conditional branches in a row with essentially no slack between
#     them, stressing how quickly the fetch/predict front-end can resolve
#     and recover from consecutive branches (including, every other pass,
#     a misprediction immediately after a previous branch's recovery).
#   - Each branch's comparison operand is produced by the IMMEDIATELY
#     preceding instruction (distance-0 RAW hazard forwarded straight into
#     the branch comparator) -- the worst-case forwarding distance,
#     combined with branch resolution, checking that a mispredict flush
#     doesn't leave stale forwarded data behind.
#   - Each of the 8 branch sites individually tests parity of (i + k) for
#     k = 1..8, which strictly alternates taken/not-taken across outer
#     iterations (same "hard" character as Test 3, just spread across
#     8 tightly-packed distinct PCs instead of one).
#
# Per outer iteration, exactly 4 of the 8 branches are taken regardless of
# i's parity (k=1..8 contains 4 even, 4 odd values), so over 300 outer
# iterations the taken count is exactly 300 * 4 = 1200.
#
# Expected result: a0 = 1 (pass) if t2 == 1200 at the end.
# =============================================================================

.section .text
.globl _start

_start:
    li   t0, 0            # outer loop index i
    li   t1, 300            # outer iterations
    li   t2, 0                # accumulator: counts taken branches

bb_loop:
    addi t3, t0, 1
    andi t4, t3, 1
    beqz t4, bb1
    addi t2, t2, 1
bb1:
    addi t3, t0, 2
    andi t4, t3, 1
    beqz t4, bb2
    addi t2, t2, 1
bb2:
    addi t3, t0, 3
    andi t4, t3, 1
    beqz t4, bb3
    addi t2, t2, 1
bb3:
    addi t3, t0, 4
    andi t4, t3, 1
    beqz t4, bb4
    addi t2, t2, 1
bb4:
    addi t3, t0, 5
    andi t4, t3, 1
    beqz t4, bb5
    addi t2, t2, 1
bb5:
    addi t3, t0, 6
    andi t4, t3, 1
    beqz t4, bb6
    addi t2, t2, 1
bb6:
    addi t3, t0, 7
    andi t4, t3, 1
    beqz t4, bb7
    addi t2, t2, 1
bb7:
    addi t3, t0, 8
    andi t4, t3, 1
    beqz t4, bb8
    addi t2, t2, 1
bb8:
    addi t0, t0, 1
    blt  t0, t1, bb_loop

    li   t5, 1200
    beq  t2, t5, pass7
    li   a0, 0                  # fail
    j    done7
pass7:
    li   a0, 1                  # pass
done7:
    ebreak
