#include <bits/stdc++.h>
#define MM 200002
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
typedef long long ll;
ll n, dp[MM];
struct st{
  ll s,t,v;
  st() : s(0), t(0), v(0) {}
  st(ll p1, ll p2, ll p3) : s(p1), t(p2), v(p3) {}
  friend bool operator<(const st &x, const st &y){
      return (x.t < y.t);
  }
} a[MM];
int k;
int main(){
    sc(n); sc(k);
    for(int i = 1; i <= k; i++){
        sc(a[i].s); sc(a[i].t);
        a[i].v = a[i].t - a[i].s + 1;
    }
    sort(a+1,a+k+1);
    for(int i = 1; i <= k; i++){
        dp[i] = max(dp[i-1], a[i].v + dp[lower_bound(a+1, a+k+1, st(0,a[i].s,0)) -a-1]);
    }
    printf("%lld\n", n - dp[k]);
    return 0;
}