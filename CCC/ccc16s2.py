q = int(input())
n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
a.sort()
b.sort()

if q == 2:
	a.reverse()

ans = 0
for i in range(n):
	ans += max(a[i], b[i])
	
print(ans)