#include <bits/stdc++.h>
using namespace std;
int N, mod = 1e9+7;
long long ans = 1;
int main(){
    scanf("%d",&N);
    if(N%3 == 1){
        N -= 4;
        ans<<=2;
    }
    while(N >= 3){
        N -= 3;
        ans = (ans*3) % mod;
    }
    if(N)
        ans<<=1;
    printf("%lld\n", ans % mod);
    return 0;
}