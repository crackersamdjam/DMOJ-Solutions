import sys
input = sys.stdin.readline
l = int(input())
n = int(input())
arr = list()
for i in range(n):
	a, b = map(int, input().split())
	arr.append([a, b])

arr.append([l, l])
arr.sort()

ans = 0
r = 0
for i in arr:
	if i[0] <= r:
		r = max(r, i[1])
	else:
		ans = max(ans, i[0]-r)
		r = i[1]

print(ans)