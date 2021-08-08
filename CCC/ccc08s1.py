import sys
input = sys.stdin.readline
low = 300
city = "none"
while 1:
	a, b = input().split()
	b = int(b)
	if b < low:
		low = b
		city = a
	if a == "Waterloo":
		break

print(city)