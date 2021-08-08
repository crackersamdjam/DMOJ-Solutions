n = int(input())
mx = (0, 0, 0)
for i in range(n):
	s = input()
	v = int(input())
	mx = max(mx, (v, -i, s))
print(mx[2])