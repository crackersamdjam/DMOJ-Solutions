import sys
input = sys.stdin.readline
anslis=list()
a=int(input())
if a%3==0:
    for i in range(int(a/3)):
        anslis.append(3)
elif a%3==1:
    anslis.append(2)
    anslis.append(2)
    for y in range(int((a-4)/3)):
        anslis.append(3)
elif a%3==2:
    anslis.append(2)
    for x in range(int((a-2)/3)):
        anslis.append(3)
ans=1
b=int(10**9+7)
for z in anslis:
    ans=ans*z%b
print(ans)