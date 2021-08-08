import sys
n, k = map(int, sys.stdin.readline().split())
v = [None]*n
ans = 0
for i in range(n):
    a, b = map(int, sys.stdin.readline().split())
    ans += a
    v[i] = max(a-b, 0)
v.sort(reverse = True)
for i in range(k):
    ans -= v[i]
print(ans)