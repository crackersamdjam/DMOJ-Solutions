#include <bits/stdc++.h>
#define MM 100002
#define f first
#define s second
#define scan(x) scanf("%d", &x);
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
ll ans;
pii ax[MM], ay[MM];
int N, lim = 1e9;

int main(){
    
    scan(N);
    
    for(int i = 0,a,b; i < N; i++){
        scan(a); scan(b);
        ax[i].f = ay[i].s = a;
        ax[i].s = ay[i].f = b;
    }
    
    sort(ax, ax+N);
    sort(ay, ay+N);
    
    for(int i = 0; i < N; i++){
        pii cur = ax[i];
        ll cnt = 1;
        cnt *= upper_bound(ax, ax+N, mp(cur.f, lim)) - upper_bound(ax,ax+N, mp(cur.f, cur.s));
        cnt *= lower_bound(ax, ax+N, mp(cur.f, cur.s)) - lower_bound(ax, ax+N, mp(cur.f, -lim));
        
        cnt *= upper_bound(ay, ay+N, mp(cur.s, lim)) - upper_bound(ay,ay+N, mp(cur.s, cur.f));
        cnt *= lower_bound(ay, ay+N, mp(cur.s, cur.f)) - lower_bound(ay, ay+N, mp(cur.s, -lim));
        
        ans += cnt;
    }
    printf("%lld\n", ans*2);
    return 0;
}