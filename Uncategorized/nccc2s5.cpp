#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
typedef pair<int, int> pii;
const int MM = 1001;

int N, M, Q, par[MM], dis[MM];
vector<pii> adj[MM];

inline int find(int x){
    while(x != par[x]){
        x = par[x];
        par[x] = par[par[x]];
    }
    return x;
}

struct edge{
    int a, b, c, d;
    inline bool merge(){
        int fa = find(a), fb = find(b);
        if(fa != fb){
            par[fa] = fb;
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
            return 1;
        }
        return 0;
    }
    friend bool operator<(const edge &x, const edge &y){
        return x.c > y.c;
    }
} edges[5001];

inline void build(){
    
    for(int i = 1; i <= N; i++){
        adj[i].clear();
        par[i] = i;
    }
    
    sort(edges+1, edges+M+1);
    int cnt = 0;
    for(int i = 1; i <= M; i++){
        if(edges[i].merge()){
            if(++cnt == N-1)
                break;
        }
    }
}

void dfs(int cur, int pre){
    
    for(auto &e: adj[cur]){
        if(e.first == pre)
            continue;
        dis[e.first] = min(dis[cur], e.second);
        dfs(e.first, cur);
    }
}

int main(){
    
    scan(N, M);
    
    for(int i = 1,a,b,c; i <= M; i++){
        scan(a, b, c);
        edges[i] = {a, b, c, i};
    }
    
    build();
    
    scan(Q);
    
    for(int i = 0,op,m,x,a,b,w; i < Q; i++){
        scan(op);
        if(op == 1){
            scan(m, x);
            for(int j = 1; j <= M; j++){
                if(edges[j].d == m){
                    edges[j].c = x;
                    break;
                }
            }
            build();
        }
        else{
            scan(a, b, w);
            memset(dis, 0, sizeof dis);
            dis[a] = INT_MAX;
            dfs(a, -1);
            printf("%d\n", dis[b] >= w);
        }
    }
    
    return 0;
}