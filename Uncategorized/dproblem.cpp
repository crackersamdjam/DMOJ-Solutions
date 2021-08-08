#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;

void init(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
    #endif
}

#ifdef ONLINE_JUDGE
using ll = __int128;
#else
using ll = long long;
#endif
const ll base = 131, base2 = 31;
ll mod1, mod2;
const int MM = 1e5+5;

int n, m;
ll a[MM], cnt[MM];
ll p1[MM], p2[MM];
map<pair<ll, ll>, ll> mp;

int main(){
    init();
    scan(n, m);
    p1[0] = p2[0] = 1;
    for(int i = 1; i <= n; i++){
        scan(a[i]);
        p1[i] = p1[i-1]*base;
        p2[i] = p2[i-1]*base2;
    }
    for(int i = 1; i <= m; i++){
        mod1 += p1[i];
        mod2 += p2[i];
    }
    ll h1 = 0, h2 = 0;;
    for(int i = 1; i <= n; i++){
        h1 += p1[a[i]];
        h1 %= mod1;
        h2 += p2[a[i]];
        h2 %= mod2;
        mp[{h1, h2}]++;
        // print(i, h);
    }
    mp[{0, 0}]++;
    ll ans = 0;
    for(auto i: mp)
        ans += i.second*(i.second-1)/2;
    
    print(ans);

    return 0;
}