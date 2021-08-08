last = 0
ds = ['right', 'left']
while 1:
	s = input()
	if s == '99999':
		break

	d = int(s[0]) + int(s[1])
	if d:
		last = d%2

	print(ds[last], s[2:])