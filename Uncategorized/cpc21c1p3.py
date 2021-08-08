import sys
input = sys.stdin.readline
t = int(input())
for _ in range(t):
	a, b, c = map(int, input().split())
	assert b-c > 0
	tot = (b-c)**2

	between = max(0, tot - (a+c)**2)
	inner =  max(0, a-c)**2
	outer = min(b-c, max(0, c-a))**2

	print((between+inner+outer) / tot)
	# print(between, inner, outer)