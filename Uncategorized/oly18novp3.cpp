#include <bits/stdc++.h>
#define MM 100002
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
typedef long long ll;
int N, M, a[MM];
inline bool f(ll n){
    int k = M-1;
    ll sum = 0;
    for(int i = 0; i < N; i++){
        if(a[i] > n)
            return 0;
        if(sum + a[i] > n){
            sum = a[i];
            k--;
            if(k < 0)
                return 0;
        }else
            sum += a[i];
    }
    return k >= 0;
}
int main(){
    sc(N); sc(M);
    for(int i = 0; i < N; i++)
        sc(a[i]);
    ll ans = LLONG_MAX;
    ll l = 0,m, r = N *(ll)(1e9);
    while(l <= r){
        m = (l+r)/2;
        if(f(m)){
            ans = min(ans, m);
            r = m-1;
        }else
            l = m+1;
    }
    printf("%lld\n", ans);
    return 0;
}