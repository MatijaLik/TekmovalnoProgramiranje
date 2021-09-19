n  = int(input())
ans = 0
for i in range(n):
    s = input().split()
    if s[2] != 'OK':
        ans += 20
print(ans)