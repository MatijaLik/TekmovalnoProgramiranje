

nlimit = 310
start = 1e200

memo = [[0 for x in range(nlimit)] for y in range(nlimit)] 

def dp(x, y, w, h):
    if(x == 0 or y == 0): 
        memo[x][y] = 0
        return 0
    if(memo[x][y] != 0):
        return memo[x][y]
    if(x == w and y == h):
        memo[x][y] = dp(x-1, y, w, h) + dp(x, y-1, w, h)
        return memo[x][y]
    if(x == w):
        memo[x][y] = dp(x-1, y, w, h)/2 + dp(x, y-1, w, h)
        return  memo[x][y]
    if(y == h):
        memo[x][y] = dp(x-1, y, w, h) + dp(x, y-1, w, h)/2
        return  memo[x][y]

    memo[x][y] = (dp(x-1, y, w, h) + dp(x, y-1, w, h))/2
    return memo[x][y]



def solve(cs):
    for i in range(nlimit):
        for j in range(nlimit):
            memo[i][j] = 0
        
    memo[1][1] = start

    ans = 0
    
    ips = input().split()

    w = int(ips[0])
    h = int(ips[1])
    l = int(ips[2])
    u = int(ips[3])
    r = int(ips[4])
    d = int(ips[5])

    
    ##prvo gremo zgoraj (l, u) (r, u)
    for i in range(l, r+1):
        ans += dp(i, u, w, h)
        if(u == 1):
            break
        if(i != l):
            ans -= dp(i-1, u, w, h)/2

    ##od (l, u) do (l, d)
    for i in range(u+1, d+1):
        if(l == 1):
            break
        else:
            ans += dp(l, i, w, h)
            ans -= dp(l, i-1, w, h)/2


    print("Case #" + str(cs) + ": %10.8f" % (1-(ans/start)))




    
t = int(input())
i = 1

for l in range(t):
    solve(i)
    i += 1

