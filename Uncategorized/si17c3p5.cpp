#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define f first
#define s second
//#define DEBUG
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int MM = 1e5+2;
vector<pii> adj[MM];
int N, sz[MM], cent, tot;
ll ans = 0;
unordered_map<int, int> cnt;
bool vis[MM];
vector<int> vec;

int getdis(int cur, int pre){
    sz[cur] = 1;
    for(const auto &e: adj[cur]){
        if(e.f != pre && !vis[e.f])
            sz[cur] += getdis(e.f, cur);
    }
    return sz[cur];
}
int findcent(int cur, int pre){
    for(auto &e: adj[cur]){
        if(!vis[e.f] && e.f != pre && sz[e.f]*2 > tot)
            return findcent(e.f, cur);
    }
    return cur;
}
void dfs(int cur, int pre, int val){
    vec.push_back(val);
    ans += cnt[1-val] + cnt[-1-val];
    for(auto &e: adj[cur]){
        if(e.f != pre && !vis[e.f]){
            dfs(e.f, cur, val+e.s);
        }
    }
}
void go(int root){
    cent = -1;
    
    getdis(root, -1);
    if(sz[root] == 1)
        return;
    //only one node left
    
    tot = sz[root];
    cent = findcent(root, -1);

#ifdef DEBUG
    printf("root %d\n", root);
    printf("cent %d\n", cent);
    assert(cent != -1);
#endif
    
    vis[cent] = 1; //block
    
    cnt.clear();
    cnt[0] = 1;
    for(auto &e: adj[cent]){
        if(!vis[e.f]){
            vec.clear();
            dfs(e.f, -1, e.s);
            for(auto &i: vec)
                cnt[i]++;
        }
    }
    for(auto &e: adj[cent]){
        if(!vis[e.f])
            go(e.f);
    }
}
int main(){
    scanf("%d",&N);
    char c;
    for(int i = 0,a,b; i < N-1; i++){
        scanf("%d%d %c",&a,&b,&c);
        adj[a].push_back({b, (c == 'r' ? 1 : -1)});
        adj[b].push_back({a, (c == 'r' ? 1 : -1)});
    }
    go(1);
    printf("%lld\n", ans - (N-1));
    return 0;
}