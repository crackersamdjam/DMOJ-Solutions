import string
s = input()
for c in string.ascii_lowercase:
	if c not in s:
		print(c)
		break