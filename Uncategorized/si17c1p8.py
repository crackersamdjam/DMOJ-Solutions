import sys
n, t = map(int, sys.stdin.readline().split())
a = list(map(int, sys.stdin.readline().split()))
ans = 0

def go(i, s):
    if i == n:
        if s == t:
            global ans
            ans += 1
        return
    go(i+1, s)
    go(i+1, s+a[i])

go(0, 0)
print(ans)