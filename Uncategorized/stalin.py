n = input()
mx = -(1<<31)
a = map(int, input().split(' '))
for i in a:
	if i >= mx:
		print(mx := i, end=' ')