#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using ll = long long;
constexpr int MM = 2e5+2;
ll base = 131, mod = 1e15+37;

int n;
char s[MM];
ll hs[MM], p[MM];

#include <ext/pb_ds/assoc_container.hpp>
__gnu_pbds::gp_hash_table<ll, __gnu_pbds::null_type> mp;

bool run(int m){
    mp.clear();
    ll h = s[1];
    for(int i = 2; i < m; i++)
        h = (h*base + s[i])%mod;
    for(int i = m; i <= n; i++){
        h = (h*base + s[i] - s[i-m]*p[m])%mod;
        if(h < 0)
            h += mod;
        if(mp.find(h) != mp.end())
            return 1;
        mp.insert(h);
    }
    return 0;
}

int main(){
    scanf("%d %s", &n, s+1);
    p[0] = 1;
    for(int i = 1; i <= n; i++){
        p[i] = p[i-1]*base%mod;
    }
    
    int l = 1, m, r = n;
    while(l <= r){
        m = (l+r)/2;
        if(run(m))
            l = m+1;
        else
            r = m-1;
    }
    print(r);
    
    return 0;
}