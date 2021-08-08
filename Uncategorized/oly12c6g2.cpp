#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MM = 1e5+2;

vector<pii> adj[MM];
int n, sz[MM], tot;
bool vis[MM];

int getsz(int cur, int pre){
    sz[cur] = 1;
    for(auto e: adj[cur]){
        if(e.first != pre and !vis[e.first])
            sz[cur] += getsz(e.first, cur);
    }
    return sz[cur];
}

int findcent(int cur, int pre){
    for(auto e: adj[cur]){
        if(e.first != pre and !vis[e.first] and sz[e.first]*2 > tot)
            return findcent(e.first, cur);
    }
    return cur;
}

ll ans;
int paa[MM<<1], pab[MM<<1], taa[MM<<1], tab[MM<<1];
int *pa = paa+MM, *pb = pab+MM, *ta = taa+MM, *tb = tab+MM;
int tmn, tmx, pmn, pmx;

void dfs(int cur, int pre, int val, int mx, int mn){
    
    if(mn <= val and val <= mx)
        pa[val]++;
    else
        pb[val]++;
    
    mx = max(mx, val);
    mn = min(mn, val);
    pmx = max(pmx, val);
    pmn = min(pmn, val);
    
    if(vis[cur])
        return;
    
    for(auto e: adj[cur]){
        if(e.first != pre)
            dfs(e.first, cur, val+e.second, mx, mn);
    }
}

void go(int rt){
    tot = getsz(rt, 0);
    if(tot == 1)
        return;
    
    int cent = findcent(rt, 0);
    vis[cent] = 1;
    
    for(auto e: adj[cent]){
        //don't "if vis, continue" because need edges, not nodes
        
        dfs(e.first, cent, e.second, 0, 0);
        
        for(int i = pmn; i <= pmx; i++){
            ans += (ll)pa[i]*(ta[-i] + tb[-i]) + (ll)pb[i]*ta[-i];
        }
        for(int i = pmn; i <= pmx; i++){
            ta[i] += pa[i];
            tb[i] += pb[i];
            pa[i] = pb[i] = 0;
        }
        tmx = max(tmx, pmx);
        tmn = min(tmn, pmn);
        pmn = pmx = 0;
    }
    for(int i = tmn; i <= tmx; i++)
        ta[i] = tb[i] = 0;
    tmn = tmx = 0;
    
    for(auto e: adj[cent]){
        if(!vis[e.first])
            go(e.first);
    }
}

int main(){
    scan(n);
    for(int i = 0,a,b,c; i < n-1; i++){
        scan(a, b, c);
        c = c*2-1;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    
    go(1);
    
    print(ans);
    
    return 0;
}