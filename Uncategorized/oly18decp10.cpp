#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
const int MM = 250, inf = 0x3f3f3f3f;

int N, M, dis[MM], par[MM], adj[MM][MM];
bool vis[MM];


inline void sp(){
    
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    par[1] = -1;
    dis[1] = 0;
    
    for(int i = 1; i <= N; i++){
        int node = -1, mindis = inf;
        
        for(int j = 1; j <= N; j++){
            if(!vis[j] && dis[j] < mindis){
                mindis = dis[j];
                node = j;
            }
        }
        
        if(node == -1)
            break;
        
        vis[node] = 1;
        for(int j = 1; j <= N; j++){
            if(dis[node] + adj[node][j] < dis[j]){
                dis[j] = dis[node] + adj[node][j];
                par[j] = node;
            }
        }
    }
}
int main(){
    
    memset(adj, 0x3f, sizeof(adj));
    
    scan(N, M);
    for(int i = 0,a,b,c; i < M; i++){
        scan(a, b, c);
        adj[a][b] = adj[b][a] = c;
    }
    
    sp();
    int dist = dis[N], ans = 0;
    int cur = N, pre = par[N];
    
    while(pre != -1){
        adj[pre][cur] *= 2;
        sp();
        ans = max(ans, dis[N]);
        adj[pre][cur] /= 2;
        
        cur = pre;
        pre = par[pre];
    }
    print(ans - dist);
    return 0;
}