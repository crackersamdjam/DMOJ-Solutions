#include <bits/stdc++.h>
using namespace std;
const int MM = 1002, inf = 0x3f3f3f3f;

int N, par[MM], adj[MM][MM], adjb[MM][MM], cost[MM][MM], p[12], ans = INT_MAX;
//edge can have at most 2 pens, a, b
//edge from i-j touches a/b

inline void init(){
    for(int i = 0; i < MM; i++)
        par[i] = i;
}

inline int find(int x){
    while(x != par[x]){
        x = par[x];
        par[x] = par[par[x]];
    }
    return x;
}

struct edge{
    int a, b, w;
    friend bool operator<(const edge &x, const edge &y){
        return x.w < y.w;
    }
    inline bool merge(){
        int fa = find(a), fb = find(b);
        if(fa != fb){
            par[fa] = fb;
            return 1;
        }
        return 0;
    }
};
vector<edge> edges;

inline int mst(){
    
    int ret = 0, cnt = 0;
    sort(edges.begin(), edges.end());
    init();
    
    for(auto &e: edges){
        if(e.merge()){
            ret += e.w;
            if(++cnt == N-1)
                break;
        }
    }
    
    return ret;
}

int main(){
    
    memset(cost, 0x3f, sizeof cost);
    
    scanf("%d", &N);
    
    for(int i = 1,n; i <= N; i++){
        scanf("%d", &n);
        
        for(int j = 0; j < n; j++)
            scanf("%d", p+j);
        
        p[n] = p[0];
    
        for(int j = 0,c; j < n; j++){
            scanf("%d", &c);
            
            cost[p[j]][p[j+1]] = cost[p[j+1]][p[j]] = min(cost[p[j]][p[j+1]], c);
            //cost of the edge from p[j] to p[j+1]
            
            //that edge connects adj[p[j][p[j+1]] and adjb
            
            if(!adj[p[j]][p[j+1]])
                adj[p[j]][p[j+1]] = adj[p[j+1]][p[j]] = i;
            else
                adjb[p[j]][p[j+1]] = adjb[p[j+1]][p[j]] = i;
        }
    }
    
    for(int i = 1; i < MM; i++){
        for(int j = 1; j < MM; j++){
            if(cost[i][j] != inf && adj[i][j] && adjb[i][j])
                edges.push_back({adj[i][j], adjb[i][j], cost[i][j]});
        }
    }
    
    ans = mst();
    
    for(int i = 1; i < MM; i++){
        for(int j = 1; j < MM; j++){
            if(cost[i][j] != inf && adj[i][j] != 0 && adjb[i][j] == 0)
                edges.push_back({adj[i][j], adjb[i][j], cost[i][j]});
        }
    }
    
    //now considering outside
    N++;
    ans = min(ans, mst());
    
    printf("%d\n", ans);
    
    return 0;
}