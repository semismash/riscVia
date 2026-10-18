# =============================================================================
# Test 3: Strictly alternating taken / not-taken branch
#
# Metric: worst-case accuracy floor for a 2-bit bimodal local predictor.
# A branch that strictly alternates T,N,T,N,... cannot be tracked by a
# saturating counter (it will typically sit at a "weakly" state and
# mispredict on every transition), so expected accuracy is close to 0%
# (or the complement, depending on which phase the counter lands in,
# i.e. it will be wrong almost every single time rather than converging).
# This is a useful sanity check against Test 1's near-100% ceiling, and
# confirms the predictor isn't doing something smarter than bimodal
# (e.g. no alternating-pattern detection).
#
# 2000 iterations -> this one branch resolves 2000 times.
#
# Expected result: a0 = 1 (pass) if t3 == 1000 at the end
# (half the iterations take the not-taken path and execute the addi).
# =============================================================================

.section .text
.globl _start

_start:
    li   t0, 0                # iteration counter
    li   t1, 0                 # toggle flag, flips every iteration
    li   t2, 2000               # total iterations
    li   t3, 0                 # accumulator (counts not-taken executions)

loop3:
    xori t1, t1, 1
    beqz t1, skip3               # alternates taken/not-taken every single iteration
    addi t3, t3, 1                 # only runs on the not-taken path
skip3:
    addi t0, t0, 1
    blt  t0, t2, loop3

    li   t4, 1000
    beq  t3, t4, pass3
    li   a0, 0                     # fail
    j    done3
pass3:
    li   a0, 1                     # pass
done3:
    ebreak
