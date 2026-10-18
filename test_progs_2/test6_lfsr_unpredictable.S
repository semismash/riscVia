# =============================================================================
# Test 6: Data-dependent unpredictable branch (16-bit Galois LFSR)
#
# Metric: true "hard branch" entropy baseline. A maximal-length LFSR
# produces a bit sequence with no short repeating period (period =
# 2^16 - 1 here), so a single per-PC 2-bit saturating counter has nothing
# exploitable to lock onto -- expected accuracy should sit close to 50%,
# giving you a floor to compare against Test 1's ~100% ceiling and
# Test 3's strict-alternation worst case.
#
# Galois LFSR update (taps = 0xB400, seed = 0xACE1):
#   lsb = state & 1
#   state >>= 1
#   if (lsb) state ^= taps        <-- this is the branch under test
#
# Verified by simulation (see accompanying notes): after 2000 iterations,
# final state = 0x4B06, and the branch is taken (xor applied) 992/2000
# times (~49.6%), confirming the sequence is close to balanced.
#
# Expected result: a0 = 1 (pass) if s0 == 0x4B06 and s1 == 992.
# =============================================================================

.section .text
.globl _start

_start:
    li   s0, 0xACE1        # LFSR state (seed, must be non-zero)
    li   t5, 0xB400          # tap mask (16-bit maximal-length Galois LFSR)
    li   t6, 0                 # iteration counter
    li   s2, 2000                # total iterations
    li   s1, 0                    # count of taken (xor-applied) branches

lfsr_loop:
    andi t0, s0, 1                  # extract LSB -- the pseudo-random bit
    srli s0, s0, 1
    beqz t0, no_xor6                  # data-dependent, ~50/50 unpredictable branch
    xor  s0, s0, t5
    addi s1, s1, 1
no_xor6:
    addi t6, t6, 1
    blt  t6, s2, lfsr_loop

    li   t1, 0x4B06
    bne  s0, t1, fail6
    li   t2, 992
    bne  s1, t2, fail6
    li   a0, 1                         # pass
    j    done6
fail6:
    li   a0, 0                          # fail
done6:
    ebreak
