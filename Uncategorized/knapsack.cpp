#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
const int MM = 5002;

int n, m;
ll dp[MM], ans = -1e9;

struct st{
    ll k, c, v;
};
vector<st> a;

int main(){
    
    scan(n, m);
    
    for(int t = 0; t < n; t++){
        ll k,c,v;
        scan(k, c, v);
        for(ll j = 1; j <= k; j *= 2){
            k -= j;
            a.push_back({j, c*j, v*j});
        }
        a.push_back({k, c*k, v*k});
    }
    
    for(auto it: a){
        for(int i = MM-1; i >= it.c; i--)
            dp[i] = max(dp[i], dp[i-it.c] + it.v);
    }
    
    for(int i = 1; i < MM; i++)
        dp[i] = max(dp[i], dp[i-1]);
    
    for(int i = 0,v,c; i < m; i++){
        scan(v, c);
        ans = max(ans, dp[v]-c);
    }
    
    print(ans);
    
    return 0;
}