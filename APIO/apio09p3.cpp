#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
typedef pair<int, int> pii;
const int MM = 5e5+2;

int N, M, S, P, v[MM], dfn[MM], low[MM], t, id[MM], path[MM], ptr, ans, st[MM], ed[MM], tr;
bool ins[MM];
pii adj[MM], adjr[MM];

void dfs(int cur){
    
    ins[cur] = 1;
    path[++ptr] = cur;
    dfn[cur] = low[cur] = ++t;
    
    for(int i = st[cur]; i < ed[cur]; i++){
        
        int u = adj[i].second;
        
        if(!dfn[u]){
            dfs(u);
            low[cur] = min(low[cur], low[u]);
        }
        else if(ins[u])
            low[cur] = min(low[cur], dfn[u]);
    }
    
    if(dfn[cur] == low[cur]){
        
        int u = -1;
        
        while(u ^ cur){
            u = path[ptr--];
            ins[u] = 0;
            id[u] = cur;
            if(u ^ cur)
                v[cur] += v[u];
        }
    }
}

int go(int n){
    if(~dfn[n])
        return dfn[n];
    dfn[n] = INT_MIN;
    if(id[n] == id[S])
        dfn[n] = v[n];
    for(int i = st[n]; i < ed[n]; i++){
        int u = adjr[i].second;
        dfn[n] = max(dfn[n], v[n] + go(u));
    }
    return dfn[n];
}

int main(){
    
    scan(N, M);
    
    for(int i = 0,a,b; i < M; i++){
        scan(a, b);
        adj[tr++] = {a, b};
    }
    
    sort(adj, adj+tr);
    
    int n = 1;
    for(int i = 0; i < tr; i++){
        if(adj[i].first != n){
            ed[n] = i;
            n = adj[i].first;
            st[n] = i;
        }
    }
    ed[n] = tr;
    
    for(int i = 1; i <= N; i++)
        scan(v[i]);
    
    for(int i = 1; i <= N; i++){
        if(!dfn[i])
            dfs(i);
    }
    
    tr = 0;
    for(int u = 1; u <= N; u++){
        for(int j = st[u]; j < ed[u]; j++){
            int nv = adj[j].second;
            if(id[u] ^ id[nv])
                adjr[tr++] = {id[nv], id[u]};
        }
    }
    
    memset(st, 0, sizeof st);
    memset(ed, 0, sizeof ed);
    sort(adjr, adjr+tr);
    n = 1;
    for(int i = 0; i < tr; i++){
        if(adjr[i].first != n){
            ed[n] = i;
            n = adjr[i].first;
            st[n] = i;
        }
    }
    ed[n] = tr;
    
    memset(dfn, -1, sizeof dfn);
    scan(S, P);
    
    for(int i = 0; i < P; i++){
        scan(n);
        ans = max(ans, go(id[n]));
    }
    
    print(ans);
    
    return 0;
}
/*
 * pii graph
 * sort
 * store beg-end for each node
 */