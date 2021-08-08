d = dict()
d['0']='O'
d['1']='l'
d['3']='E'
d['4']='A'
d['5']='S'
d['6']='G'
d['8']='B'
d['9']='g'
s = input()
for c in s:
	print(d[c] if c in d else c, end='')