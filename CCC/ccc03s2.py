n = int(input())
vowels = 'aeiou'
for _ in range(n):
	ends = []
	for i in range(4):
		s = input().split()[-1].lower()
		ends.append(s)
		for j in range(len(s)-1, -1, -1):
			if s[j] in vowels:
				ends[i] = s[j:]
				break

	# print(ends)
	if len(set(ends)) == 1:
		print('perfect')
	elif ends[0] == ends[1] and ends[2] == ends[3]:
		print('even')
	elif ends[0] == ends[2] and ends[1] == ends[3]:
		print('cross')
	elif ends[0] == ends[3] and ends[1] == ends[2]:
		print('shell')
	else:
		print('free')