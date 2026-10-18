# =============================================================================
# Test 5: Recursive function via JAL/JALR (JALR return-target prediction)
#
# Metric: indirect-branch (JALR / `ret`) target prediction.
#
# fib(n) makes TWO recursive calls (call site A: fib(n-1), call site B:
# fib(n-2)) that share a single epilogue `ret` instruction. As the call
# tree unwinds, that one `ret` PC has to return to call site A sometimes
# and call site B other times, in an order dictated by the tree structure
# -- NOT a simple fixed period. Without a return-address stack (RAS), a
# predictor that stores "last target seen" per PC will mispredict heavily
# here, since the correct target alternates irregularly between two very
# different addresses. This isolates JALR/return prediction specifically,
# separate from the direct/PC-relative conditional branches tested
# elsewhere.
#
# fib(15) = 610, computed via ~1973 total calls/returns (2*fib(16)-1),
# giving thousands of JALR resolutions from one invocation.
#
# NOTE: requires a valid stack pointer. STACK_TOP below is a placeholder --
# set it to a real writable RAM address in your memory map before running.
#
# Expected result: a0 = 1 (pass) if fib(15) == 610.
# =============================================================================

.section .text
.globl _start

.equ STACK_TOP, 0x00002000     # TODO: set to a valid RAM address for your memory map

_start:
    li   sp, STACK_TOP

    li   a0, 15            # compute fib(15)
    jal  ra, fib
    mv   s2, a0              # save result (fib(15) should be 610)

    li   t0, 610
    beq  s2, t0, pass5
    li   a0, 0                # fail
    j    done5
pass5:
    li   a0, 1                # pass
done5:
    ebreak

# ---------------------------------------------------------------------------
# fib(n): a0 = n (input), returns a0 = fib(n)
# Naive recursive implementation -- O(fib(n)) calls, two call sites per
# invocation, one shared return point.
# ---------------------------------------------------------------------------
fib:
    addi sp, sp, -16
    sw   ra, 12(sp)
    sw   s0, 8(sp)
    sw   s1, 4(sp)

    mv   s0, a0              # s0 = n

    li   t1, 2
    blt  s0, t1, fib_base      # base case: n < 2

    addi a0, s0, -1
    jal  ra, fib                 # call site A: fib(n-1)
    mv   s1, a0                    # s1 = fib(n-1)

    addi a0, s0, -2
    jal  ra, fib                     # call site B: fib(n-2)
    add  a0, a0, s1                    # a0 = fib(n-1) + fib(n-2)

    j    fib_ret

fib_base:
    mv   a0, s0                        # fib(0) = 0, fib(1) = 1

fib_ret:
    lw   ra, 12(sp)
    lw   s0, 8(sp)
    lw   s1, 4(sp)
    addi sp, sp, 16
    ret                                   # single JALR point: target varies (site A or B)
