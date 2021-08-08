limit = int(input())
current = int(input())
multiply = int(input())
day = 0
total = current

while total <= limit:
	day += 1
	current *= multiply
	total += current
	# print('on day', day, ',', current, 'people are infected. and the total is', total)

print(day)