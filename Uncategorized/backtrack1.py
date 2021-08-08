n = int(input())
ans = [0 for i in range(n+1)]

def go(x):
	if ans[x]:
		return ans[x]
	ans[x] = 1
	for i in range(1, x//2+1):
		ans[x] += go(x - i*2)
	return ans[x]

print(go(n))