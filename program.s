# =============================================================================
# Test 1: Tight loop, strongly-biased backward branch
#
# Metric: steady-state branch prediction accuracy ceiling.
#   - Single branch PC, taken 4999/5000 times.
#   - After the 2-bit saturating counter warms up (~2 iterations), the
#     predictor should converge to effectively 100% accuracy on this branch.
#   - Also exercises BTB hit rate on a single hot entry (same PC, repeated
#     target) -- should be a BTB hit every iteration after the first.
#
# Expected result: a0 = 1 (pass) if t1 == 5000 at the end.
# =============================================================================

.section .text
.globl _start

_start:
    li   t0, 5000           # loop trip count
    li   t1, 0               # accumulator (counts iterations executed)

loop1:
    addi t1, t1, 1
    addi t0, t0, -1
    bnez t0, loop1            # backward branch: taken 4999/5000 times

    li   t2, 5000
    beq  t1, t2, pass1
    li   a0, 0                # fail
    j    done1
pass1:
    li   a0, 1                # pass
done1:
    ebreak
