import sys
sys.setrecursionlimit(1500)
from decimal import *
getcontext().prec = 100


N, K, C = map(int,input().split(" "))

comb = []
for i in range(105):
    temp = []
    for j in range(105):
        temp.append(0)
    comb.append(temp)


def c(n, k):
    if(n == 0 or k > n):
        comb[n][k] = 0
        return 0
    if(k == 0 or k == n):
        comb[n][k] = 1
        return 1
    if(comb[n][k]!=0):
        return comb[n][k]


    comb[n][k] = c(n-1, k) + c(n-1, k-1)
    return comb[n][k]

c(100, 100)


def P(n, good):
    if(good > K):
        return 0
    if(n == N):
        if(good == K):
            return 1
        else:
            return 0

    return (c(n, good)*c(N-n, K-good))/c(N, K)

dp = []
dp.append(0)

for n in range(1, N+1):
    sum = 1
    for i in range(n):
        sum += P(n, n-i)*dp[i]
    dp.append(sum/(1-P(n, 0)))
    

dp[N] *= C
print('%.10f' %  dp[N])
