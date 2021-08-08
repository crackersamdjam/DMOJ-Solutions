#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4,popcnt,abm,mmx,tune=native")

#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
const int MM = 2e5+2;
ll inf = 1e16;

int n;
ll dp[MM][4];
vector<pair<int, int>> adj[MM];

/*
 * 0 = used for going up
 * 1 = connecting two children (one use, one not)  (parent use)
 *      && (used for going down as well (to assist op 1 and 3)
 * 2 = connecting one child (use) to parent (no use)
 * 3 = connecting parent (use) to child (no use)
 *
 * c = current, u = child, p = parent
 * dp[c][0] <- {remaining dp[u][0/2]}
 * dp[c][1] <- {choose 2 dp[u][0] + dp[v][0/1] + u.w + v.w} + {remaining dp[u][0/2]}
 * or dp[c][2] <- {choose 1 dp[u][0/1/2/3]} + rem...
 * dp[c][2] <- {choose 1 dp[u][0] + u.w + p.w} + {remaining dp[u][0/2]}
 * dp[c][3] <- {choose 1 dp[u][0/1] + u.w + p.w} + {remaining dp[u][0/2]}
 *
*/

void dfs(int cur, int pre, int pw){
    ll d1 = -inf, d2 = -inf, d3 = -inf;
    vector<ll> v = {-inf}, pref = {-inf}, suf = {-inf};
    
    for(auto e: adj[cur]){
        int u = e.first; if(u == pre) continue;
        dfs(u, cur, e.second);
        
        ll rem = max(dp[u][0], dp[u][2]);
        dp[cur][0] += rem;
        d1 = max(d1, *max_element(dp[u], dp[u]+4) - rem);
        d2 = max(d2, dp[u][0] + e.second + pw - rem);
        d3 = max(d3, max(dp[u][0], dp[u][1]) + e.second + pw - rem);
        
        v.push_back(dp[u][0] + e.second - rem);
        pref.push_back(dp[u][1] + e.second - rem); suf.push_back(dp[u][1] + e.second - rem);
    }
    
    dp[cur][3] = dp[cur][2] = dp[cur][1] = dp[cur][0];
    dp[cur][2] += d2;
    dp[cur][3] += d3;
    
    v.push_back(-inf); pref.push_back(-inf); suf.push_back(-inf);
    for(int i = suf.size()-2; i >= 0; i--)
        suf[i] = max(suf[i], suf[i+1]);
    for(int i = 1; i < pref.size(); i++)
        pref[i] = max(pref[i], pref[i-1]);
    for(int i = 1; i < v.size()-1; i++)
        d1 = max(d1, v[i] + max(pref[i-1], suf[i+1]));
    
    dp[cur][1] += d1;
    dp[cur][1] = max(dp[cur][1], dp[cur][0]);
}

int main(){
    
    scan(n);
    
    for(int i = 0,a,b,c; i < n-1; i++){
        scan(a, b, c);
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    
    dfs(1, 0, -inf);
    
    print(max(dp[1][0], dp[1][1]));
    
    
    return 0;
}