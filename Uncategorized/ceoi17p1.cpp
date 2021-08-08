#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef pair<int, int> pii;
const int MM = 1e5+2;

int n, m, p, dif[MM], dfn[MM], low[MM], t, id[MM], path[MM], ptr;
bool vis[MM];
vector<pii> in[MM], adj[MM];
char s[MM], dir[] = {'L', 'R'};

void tar(int cur){
    
    path[++ptr] = cur;
    dfn[cur] = low[cur] = ++t;
    
    for(pii e: in[cur]){
        int u = e.first, w = e.second/2;
        if(vis[w])
            continue;
        vis[w] = 1;
        if(!dfn[u]){
            tar(u);
            low[cur] = min(low[cur], low[u]);
        }
        else
            low[cur] = min(low[cur], dfn[u]);
    }
    
    if(dfn[cur] == low[cur]){
        int u;
        do{
            u = path[ptr--];
            id[u] = cur;
        } while(u != cur);
    }
}

void dfs(int cur, int pre){
    vis[cur] = 1;
    
    for(pii e: adj[cur]){
        int u = e.first, w = e.second;
        if(u == pre)
            continue;
        dfs(u, cur);
        dif[cur] += dif[u];
        
        if(dif[u])
            s[w/2] = dir[(dif[u]<0)^(w&1)];
    }
}

int main(){
    
    scan(n, m);
    
    for(int i = 0,a,b; i < m; i++){
        scan(a, b);
        in[a].push_back({b, i*2});
        in[b].push_back({a, i*2+1});
        s[i] = 'B';
    }
    
    for(int i = 1; i <= n; i++){
        //tar::vis is for edges, use dfn for nodes
        if(!dfn[i])
            tar(i);
    }
    
    for(int i = 1; i <= n; i++){
        for(auto u: in[i]){
            if(id[i] != id[u.first])
                adj[id[i]].push_back({id[u.first], u.second});
        }
    }
    
    scan(p);
    
    for(int i = 0,a,b; i < p; i++){
        scan(a, b);
        dif[id[a]]++;
        dif[id[b]]--;
    }
    
    memset(vis, 0, sizeof vis);
    
    for(int i = 1; i <= n; i++){
        if(!vis[i])
            dfs(i, 0);
    }
    
    printf("%s\n", s);
    
    return 0;
}