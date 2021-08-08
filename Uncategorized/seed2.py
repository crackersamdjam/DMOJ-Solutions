import sys
l = 1
r = 2*10**9

while 1:
	m = (l+r)//2
	print(m)
	sys.stdout.flush()

	res = input()
	if res == "OK":
		break

	if res == "FLOATS":
		r = m-1
	elif res == "SINKS":
		l = m+1
	else:
		raise Exception("idk")