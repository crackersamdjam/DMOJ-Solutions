import math
a = int(input())
b = int(input())
g = math.gcd(a, b)
a //= g
b //= g

if a%b:
	if a//b:
		print(a//b, end=' ')
	print(f'{a%b}/{b}')
else:
	print(a//b)