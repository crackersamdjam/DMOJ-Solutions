#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1e5+1, MN = 17;

int N, M, Q, dep[MM], dfn[MM], low[MM], t, tt, in[MM], out[MM], lca[MN][MM];
vector<int> adj[MM];

void dfs(int cur, int pre){
    
    dfn[cur] = low[cur] = ++t;
    dep[cur] = dep[pre]+1;
    in[cur] = ++tt;
    lca[0][cur] = pre;
    
    for(int u: adj[cur]){
        if(u == pre)
            continue;
        if(!dfn[u]){
            dfs(u, cur);
            low[cur] = min(low[cur], low[u]);
        }
        else
            low[cur] = min(low[cur], dfn[u]);
    }
    
    out[cur] = ++tt;
}

bool is_par(int a, int b){
    return in[a] <= in[b] && out[a] >= out[b];
}

int main(){
    
    memset(lca, -1, sizeof lca);
    
    scan(N, M);
    
    for(int i = 0,a,b; i < M; i++){
        scan(a, b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1, 0);
    
    for(int i = 1; i < MN; i++){
        for(int j = 1; j <= N; j++){
            if(~lca[i-1][j])
                lca[i][j] = lca[i-1][lca[i-1][j]];
        }
    }
    
    scan(Q);
    
    for(int z = 0,op,a,b,c,u,v; z < Q; z++){
        scan(op, a, b);
        
        if(op == 1){
            scan(u, v);
            if(is_par(u, v))
                swap(u, v);
            
            if(low[u] <= dfn[v])
                puts("yes");
            else if(is_par(u, a) ^ is_par(u, b) ^ 1)
                puts("yes");
            else
                puts("no");
        }
        else{
            scan(c);
            
            if(is_par(c, a) & is_par(c, b)){
                
                for(int i = MN; i >= 0; i--){
                    if(dep[a] - (1<<i) > dep[c])
                        a = lca[i][a];
                }
                for(int i = MN; i >= 0; i--){
                    if(dep[b] - (1<<i) > dep[c])
                        b = lca[i][b];
                }
                
                if(a == b || (low[a] < dfn[c] && low[b] < dfn[c]))
                    puts("yes");
                else
                    puts("no");
                
            }
            else if(is_par(c, a) | is_par(c, b)){
                if(is_par(c, b))
                    swap(a, b);
                
                for(int i = MN; i >= 0; i--){
                    if(dep[a] - (1<<i) > dep[c])
                        a = lca[i][a];
                }
                
                if(low[a] < dfn[c])
                    puts("yes");
                else
                    puts("no");
            }
            else
                puts("yes");
        }
    }
    
    return 0;
}