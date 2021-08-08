from decimal import *
import math
lim = 100
getcontext().prec = lim

for _ in range(int(input())):
	a, b = map(int, input().split())
	a %= b
	c = Decimal(a)/Decimal(b)
	l = len('{:f}'.format(c))-2
	print(l if l < lim else -1)