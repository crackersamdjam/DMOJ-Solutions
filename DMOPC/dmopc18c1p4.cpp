#include <bits/stdc++.h>
#define f first
#define s second
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int MM = 200002;
ll N, M, K, X, ans[MM];
pll a[MM];
int main(){
    sc(N); sc(M); sc(K); sc(X);
    if(K < X){
        printf("-1\n");
        return 0;
    }
    for(int i = 1; i <= N; i++){
        sc(a[i].f);
        a[i].s = i;
    }
    sort(a+1, a+N+1);
    for(int i = 1; i <= N; i++)
        a[i].f += a[i-1].f;
    
    if(a[X-1].f >= K || a[N].f - a[N-X].f < K){
        printf("-1\n");
        return 0;
    }
    ll cnt = 1;
    for(ll i = X; i <= N; i++){
        ll num = a[i].f - a[i-X].f;
        if(num >= K){
            for(ll j = i-X+1; j <= i; j++)
                ans[a[j].s] = cnt++;
            
            for(ll j = 1; j <= N; j++){
                if(!ans[j])
                    ans[j] = cnt++;
                printf("%lld ", ans[j]);
            }
            break;
        }
    }
    return 0;
}
/*
 * in array of f
 * find window of x values and sum >= K
 * size x-1, sum < K
 *
 * first check smallest x-1 > K
 * largest x number > K
 *
 * loop through looking for x values >= K
 */