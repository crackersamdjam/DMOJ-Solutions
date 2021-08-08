r = [0]*4
c = [0]*4

for i in range(4):
	a = list(map(int, input().split()))
	for j in range(4):
		r[i] += a[j]
		c[j] += a[j]

good = 1
S = r[0]
for i in range(4):
	if r[i] != S or c[i] != S:
		good = 0

if good:
	print('magic')
else:
	print('not magic')