S,m=input().encode(),1e9
l=t=x=s=a=0
p=i=1
for c in input():t=(t*9+ord(c))%m;p=p*9%m;l+=1
for c in S:s=(s*9+c-(i>l)*S[i-l-1]*p)%m;i+=1;v=(i-l)*(s==t);a+=v;x^=v
print(a)
print(x)