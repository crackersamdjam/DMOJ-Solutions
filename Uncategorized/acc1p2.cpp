#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
const int MM = 100002, inf = 0x3f3f3f3f;

int N, M, Q, dis[2][MM], par[MM];
vector<int> adj[MM];

inline int find(int x){
    while(x != par[x]){
        x = par[x];
        par[x] = par[par[x]];
    }
    return x;
}
struct st{
    int u, t;
};
queue<st> q;

inline int bfs(int a, int b){
    while(!q.empty())
        q.pop();
    memset(dis, 0x3f, sizeof dis);
    dis[0][a] = dis[1][b] = 0;
    q.push({a,0}); q.push({b,1});
    while(!q.empty()){
        st cur = q.front(); q.pop();
        for(int &u: adj[cur.u]){
            if(dis[cur.t][cur.u] + 1 < dis[cur.t][u]){
                dis[cur.t][u] = dis[cur.t][cur.u] + 1;
                if(dis[cur.t^1][u] != inf){
                    return dis[cur.t][u] + dis[cur.t^1][u];
                }
                q.push({u, cur.t});
            }
        }
    }
    return -1;
}

int main(){
    
    scan(N, M, Q);
    
    for(int i = 1; i <= N; i++)
        par[i] = i;
    
    for(int i = 0,a,b; i < M; i++){
        scan(a, b);
        par[find(a)] = find(b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for(int i = 0,a,b; i < Q; i++){
        scan(a, b);
        if(a == b)
            puts("0");
        else if(find(a) != find(b))
            puts("-1");
        else
            print(bfs(a, b));
    }
    return 0;
}