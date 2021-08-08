#include <bits/stdc++.h>
using namespace std;
long long a,b;
int main(){
    scanf("%lld%lld",&a,&b);
    printf("%lld\n",max(a+b, max(abs(a-b), a*b)));
    return 0;
}