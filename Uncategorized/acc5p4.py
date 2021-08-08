t = int(input())
for q in range(t):
    print("? 3 0 0 0 30 30 30", flush = True)
    a, b, c = map(int, input().split())
    print("? 1 0 %d" % ((a+30-b)//2), flush = True)
    d = int(input())
    x = 30 - (a-d+b-d)
    y = 60-a-c-x
    print("! %d" % (x*y), flush = True)