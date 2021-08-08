import sys
input = sys.stdin.readline

n = int(input())
m = int(input())
q = int(input())

a = [0]*(n+2)

for _ in range(q):
	l, r, x = map(int, input().strip().split())
	a[l] += x
	a[r+1] -= x

ans = 0
for i in range(1, n+1):
	a[i] += a[i-1]
	if a[i] < m:
		ans += 1
print(ans)