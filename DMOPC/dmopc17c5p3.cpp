#include <bits/stdc++.h>
#define MM 100002
using namespace std;
typedef long long ll;
ll arr[MM],gcd,ans,N;
inline ll f(ll a, ll b){
    if(a == 0)
        return b;
    return f(b%a,a);
}
int main(){
    scanf("%lld%lld",&N,arr);
    gcd = arr[0];
    for(int i = 1;  i < N; i++){
        scanf("%lld",arr+i);
        gcd = f(gcd,arr[i]);
    }
    if (ans == 1){
        printf("DNE\n");
        return 0;
    }
    N = gcd, ans = -1;
    while(N % 2 == 0){
        ans = 2;
        N >>= 1;
    }
    for(ll i = 3; i <= sqrtl(N); i += 2){
        while(N%i == 0){
            ans = i;
            N = N/i;
        }
    }
    if(N > 2)
        ans = N;
    ans == -1? printf("DNE"): printf("%lld",ans);
    return 0;
}