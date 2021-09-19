N, L = list(map(int, input().split()))

ans = 0

for a in range(1, L+1):
    for b in range(a, L+1):
        sum = a**N + b**N
        c = int(sum**(1/float(N)))
        if c <= L and c**N == sum:
            ans += 1

print(ans)