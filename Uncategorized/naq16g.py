import sys, math
s = sys.stdin.readline()
if(len(s) < 10):
    v = math.log(int(s), 10)
    i = 1
    sum = 0
    while sum < v:
        i += 1
        sum += math.log(i, 10)
    print(i)
else:
    i = 1
    sum = 0
    l = len(s)-2
    while sum < l:
        i += 1
        sum += math.log(i, 10)
    print(i)