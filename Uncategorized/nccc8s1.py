a = input()
b = input()
l = []
for i in range(len(b)+1):
	l.append(b[:i]+b[i+1:])
	for c in a:
		l.append(b[:i]+c+b[i+1:])
		l.append(b[:i]+c+b[i:])

l = list(set(l))
l.sort()
for s in l:
	if s != b:
		print(s)