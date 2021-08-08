cnt = 0
for i in range(6):
	if input() == 'W':
		cnt += 1

if cnt > 4:
	print(1)
elif cnt > 2:
	print(2)
elif cnt > 0:
	print(3)
else:
	print(-1)