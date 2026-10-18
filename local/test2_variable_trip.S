# =============================================================================
# Test 2: Loop with irregular / varying trip count (hysteresis test)
#
# Metric: how the 2-bit saturating counter handles a branch that is "mostly
# taken" but whose run length changes every outer iteration, including short
# runs (trip count 1, where the branch is taken 0 times before falling
# through). This stresses whether the counter needs repeated misses to
# retrain after a run-length change, vs. a simpler 1-bit predictor which
# would flip immediately.
#
# Outer loop: i = 0..49
# Inner trip count = (i % 16) + 1   (cycles through 1..16 repeatedly)
#
# Expected total inner-loop increments (t2):
#   i%16 cycles with period 16; 50 = 3*16 + 2
#   one full cycle sum of ((i%16)+1) for i%16=0..15 = sum(0..15) + 16 = 136
#   3 full cycles -> 408
#   partial cycle (i=48 -> 0+1=1, i=49 -> 1+1=2) -> +3
#   total = 411
#
# Expected result: a0 = 1 (pass) if t2 == 411 at the end.
# =============================================================================

.section .text
.globl _start

_start:
    li   t0, 0               # outer index i
    li   t1, 50                # outer trip count
    li   t2, 0                # accumulator (total inner iterations)

outer2:
    andi t3, t0, 15            # i % 16   (16 is a power of 2)
    addi t3, t3, 1              # inner trip count, range [1,16]
    mv   t4, t3                 # inner loop counter

inner2:
    addi t2, t2, 1
    addi t4, t4, -1
    bnez t4, inner2              # backward branch, run length changes every outer pass

    addi t0, t0, 1
    blt  t0, t1, outer2

    li   t5, 411
    beq  t2, t5, pass2
    li   a0, 0                   # fail
    j    done2
pass2:
    li   a0, 1                   # pass
done2:
    ebreak
