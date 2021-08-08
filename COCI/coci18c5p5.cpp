#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MM = 1e5+1;

int n, v[MM], tot, sz[MM];
ll sum[MM], req[MM], ans;
vector<pii> adj[MM];
bool vis[MM];
vector<ll> in, out;

int getsz(int cur, int pre){
    sz[cur] = 1;
    for(auto e: adj[cur]){
        int u = e.first;
        if(u != pre && !vis[u])
            sz[cur] += getsz(u, cur);
    }
    return sz[cur];
}

int findcent(int cur, int pre){
    for(auto e: adj[cur]){
        int u = e.first;
        if(!vis[u] && u != pre && sz[u]*2 > tot)
            return findcent(u, cur);
    }
    return cur;
}

void dfs1(int cur, int pre){
    
    for(auto u: adj[cur]){
        if(u.first == pre || vis[u.first])
            continue;
    
        //how much fuel needed to reach centroid
        sum[u.first] = sum[cur] + u.second - v[u.first];
        req[u.first] = max(req[cur] + u.second - v[u.first], (ll)u.second - v[u.first]);
        if(req[u.first] <= 0)
            in.push_back(-sum[u.first]);
        
        dfs1(u.first, cur);
    }
}

void dfs2(int cur, int pre){
    
    for(auto u: adj[cur]){
        if(u.first == pre || vis[u.first])
            continue;
        
        sum[u.first] = sum[cur] + u.second - v[cur];
        //opp. direction as dfs11
        
        req[u.first] = max(sum[u.first], req[cur]);
        //because if new high one, is current
        
        out.push_back(req[u.first]);
        
        dfs2(u.first, cur);
    }
}

void go(int root){
    
    getsz(root, -1);
    tot = sz[root];
    if(tot == 1)
        return;
    int cent = findcent(root, -1);
    vis[cent] = 1;
    
    in.clear();
    sum[cent] = req[cent] = 0;
    in.push_back(0);
    dfs1(cent, 0);
    
    out.clear();
    sum[cent] = req[cent] = 0;
    out.push_back(0);
    dfs2(cent, 0);
    
    sort(in.begin(), in.end());
    sort(out.begin(), out.end());
    
    int l = 0;
    for(ll i : in){
        while(l < out.size() && i >= out[l])
            l++;
        ans += l;
    }
    ans--;
    //overcounted itself
    
    for(auto u: adj[cent]){
        if(vis[u.first])
            continue;
        
        in.clear();
        sum[u.first] = sum[cent] + u.second - v[u.first];
        req[u.first] = max(req[cent] + u.second - v[u.first], (ll)u.second - v[u.first]);
        if(req[u.first] <= 0)
            in.push_back(-sum[u.first]);
        dfs1(u.first, 0);
        
        out.clear();
        sum[u.first] = sum[cent] + u.second - v[cent];
        req[u.first] = max(sum[u.first], req[cent]);
        out.push_back(req[u.first]);
        dfs2(u.first, 0);
    
        sort(in.begin(), in.end());
        sort(out.begin(), out.end());
        
        l = 0;
        for(ll i : in){
            while(l < out.size() && i >= out[l])
                l++;
            ans -= l;
        }
    }
    
    for(auto u: adj[cent]){
        if(!vis[u.first])
            go(u.first);
    }
}


int main(){
    
    scan(n);
    
    for(int i = 1; i <= n; i++)
        scan(v[i]);
    
    for(int i = 0,a,b,c; i < n-1; i++){
        scan(a, b, c);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    go(1);
    
    print(ans);
    
    return 0;
}