# =============================================================================
# Test 4: Many distinct branch PCs (BTB capacity / associativity stress)
#
# Metric: your BTB is 1024-entry, set-associative. This program generates
# 1500 DISTINCT branch sites (via .rept), each a tiny 3-iteration loop with
# its own unique PC. 1500 > 1024, so a single pass through this code is
# already enough to guarantee the working set exceeds BTB capacity -- some
# branches must either never be cached or must evict/conflict with others
# depending on your indexing/replacement policy.
#
# The whole 1500-site block is then wrapped in an outer loop that repeats
# it 4 times. On passes 2-4, re-executing the same 1500 branch PCs tests
# whether previously-learned entries survived (capacity/conflict hit) or
# were evicted and have to be re-learned (capacity/conflict miss) -- this
# is the key differentiator between "big enough BTB" and "too small."
#
# NOTE: the outer closing branch ("blt t0, t1, outer4") jumps backward over
# ~6000 instructions, which exceeds a single B-type immediate's +/-4KB
# range. Standard GNU RISC-V `as` auto-relaxes this into an inverted
# branch + jal pair by default. If your toolchain has relaxation disabled
# (-mno-relax / .option norelax), this won't assemble as-is -- let me know
# and I'll rewrite it with an explicit invert+jal.
#
# Expected total branch-body increments (t2): 1500 sites * 3 iters/site *
# 4 outer passes = 18000.
#
# Expected result: a0 = 1 (pass) if t2 == 18000 at the end.
# =============================================================================

.section .text
.globl _start

_start:
    li   t0, 0                  # outer pass counter
    li   t1, 4                   # number of outer passes
    li   t2, 0                   # global accumulator

outer4:
    .rept 1500
    li   t3, 3                    # each site: tiny fixed 3-iteration loop
1:
    addi t3, t3, -1
    addi t2, t2, 1
    bnez t3, 1b                    # distinct PC per .rept expansion
    .endr

    addi t0, t0, 1
    blt  t0, t1, outer4              # long backward branch (see note above)

    li   t5, 18000
    beq  t2, t5, pass4
    li   a0, 0                        # fail
    j    done4
pass4:
    li   a0, 1                        # pass
done4:
    ebreak
