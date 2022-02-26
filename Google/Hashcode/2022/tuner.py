import tester, patrik, parse
import random
c, p = parse.read()

best = 0
koncna_resitev = -1
for i in range(1):
    A = 1
    B = 1
    C = 1
    D = 1

    sol = patrik.solve(c, p, A, B, C, D)
    score = tester.evalviraj_ali_ko_sto_se_kaze(c, p, sol)

    if(score > best):
        print(best)
        koncna_resitev = sol
    
parse.write(koncna_resitev)
print(best)