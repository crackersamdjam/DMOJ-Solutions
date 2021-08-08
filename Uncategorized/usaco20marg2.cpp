#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;

void init(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
    #endif
}

const int MM = 2e5+5;

vector<int> adj[MM];
int n, m, c[MM], ptr, par[MM];
int out[MM];

int find(int x){
    while(x != par[x])
        x = par[x], par[x] = par[par[x]];
    return x;
}
/*
when two groups point at each other an no more merge left, then don't keep recurring
*/
void dfs(int cur){
    if(adj[cur].size() < 2)
        return;
    int p = find(adj[cur].back());
    adj[cur].pop_back();    
    // printf("dfs %d %d\n", cur, p);

    for(int u: adj[cur]){
        if(u == cur)
            continue;
        // printf("ch %d\n", u);
        u = find(u);
        if(u != p){
            // printf("merge %d %d\n", u, p);
            par[u] = p;
            if(adj[u].size() > adj[p].size())
                swap(adj[u], adj[p]);
            adj[p].insert(adj[p].end(), all(adj[u]));
        }
    }
    adj[cur].clear();
    adj[cur].emplace_back(p); //represents all ch of p
    dfs(p);
    //all of p's children merge
}

int main(){
    init();
    scan(n, m);
    for(int i = 1; i <= n; i++){
        par[i] = i;
    }
    for(int i = 0,a,b; i < m; i++){
        scan(a, b);
        adj[a].emplace_back(b);
    }
    /*
    for(int i = 1; i <= n; i++){
        int cur = find(i);
        if(adj[cur].empty())
            continue;
        int pp = adj[cur].back();
        int p = find(adj[cur].back());
        adj[cur].pop_back();    

        for(int u: adj[cur]){
            if(u == pp) continue;
            u = find(u);
            if(1){
                par[u] = p;
                if(adj[u].size() > adj[p].size())
                    swap(adj[u], adj[p]);
                adj[p].insert(adj[p].end(), all(adj[u]));
            }
        }
        adj[cur].clear();
    }
    */
    for(int i = 1; i <= n; i++)
        dfs(i);

    for(int i = 1; i <= n; i++){
        int u = find(i);
        if(!out[u]){
            out[u] = ++ptr;
        }
        out[i] = out[u];
    }
    for(int i = 1; i <= n; i++){
        print(out[i]);
    }
    
    return 0;
}