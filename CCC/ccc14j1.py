a = []
for i in range(3):
    a.append(int(input()))
if sum(a) != 180:
    print("Error")
else:
    a.sort()
    if a[0] == a[1] and a[1] == a[2]:
        print("Equilateral")
    elif a[0] == a[1] or a[1] == a[2]:
        print("Isosceles")
    else:
        print("Scalene")