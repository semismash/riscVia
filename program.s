li x1, 0           # outer counter
li x5, 50           # outer bound
outer_loop:
    li x2, 0        # inner counter
    li x6, 20        # inner bound
    inner_loop:
        addi x2, x2, 1
        blt x2, x6, inner_loop    # taken 19/20 times — predictor should learn this fast
    addi x1, x1, 1
    blt x1, x5, outer_loop        # taken 49/50 times