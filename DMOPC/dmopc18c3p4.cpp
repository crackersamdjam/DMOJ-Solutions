#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define f first
#define s second
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int MM = 2e5+2;
int K,N,n[MM],dis[MM],sz[MM];
vector<pii> adj[MM];
int root(int cur, int pre){
    int num = n[cur];
    for(const auto &e: adj[cur]){
        if(e.f != pre)
            num += root(e.f, cur);
    }
    return sz[cur] = num;
}
int cent(int cur, int pre){
    for(const auto &e: adj[cur]){
        if(e.f != pre && sz[e.f] > K/2)
            return cent(e.f, cur);
    }
    return cur;
}
void dfs(int cur, int pre){
    for(const auto &e: adj[cur]){
        if(e.f != pre){
            dis[e.f] = dis[cur] + e.s;
            dfs(e.f, cur);
        }
    }
}
int main(){
    sc(K); sc(N);
    for(int i = 0,k; i < K; i++){
        sc(k);
        n[k]++;
    }
    for(int i = 0,a,b,c; i < N-1; i++){
        sc(a); sc(b); sc(c);
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    root(1,-1);
    int rt = cent(1, -1);
    dfs(rt, -1);
    ll ans = 0;
    for(int i = 1; i <= N; i++)
        ans += (ll)dis[i]*n[i];
    
    printf("%lld\n", ans);
    return 0;
}