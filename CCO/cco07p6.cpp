#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1001;

int N, M, dfn[MM], t, low[MM], leaf;
bool vis[MM];
vector<int> adj[MM], adjc[MM];

void dfs(int cur, int pre){
    vis[cur] = 1;
    dfn[cur] = low[cur] = ++t;
    for(int u: adj[cur]){
        if(u == pre)
            continue;
        if(!vis[u]){
            dfs(u, cur);
            low[cur] = min(low[cur], low[u]);
        }
        else
            low[cur] = min(low[cur], dfn[u]);
    }
}

int main(){
    
    scan(N, M);
    
    for(int i = 0,a,b; i < M; i++){
        scan(a, b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1, -1);
    
    for(int u = 1; u <= N; u++){
        for(int v: adj[u]){
            if(low[u] ^ low[v])
                adjc[low[u]].push_back(low[v]);
        }
    }
    
    for(int i = 1; i <= N; i++)
        if(adjc[i].size() == 1)
            leaf++;
        
    print((leaf+1)/2);
    
    return 0;
}