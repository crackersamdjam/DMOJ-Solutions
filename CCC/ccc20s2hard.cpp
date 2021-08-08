#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>
constexpr int MM = 16000002;

int n, m, tr, st[MM], ed[MM], stk[MM], r;
bool vis[MM];
std::pair<int, int> adj[MM];

bool can_escape(int M, int N, std::vector<std::vector<int>> v){
    n = M, m = N;
    for(int i = 1,k; i <= n; i++){
        k = i;
        for(int j = 1; j <= m; j++, k += i){
            adj[tr++] = {k, v[i][j]};
        }
    }

    sort(adj, adj+tr);
    int nn = 1;
    for(int i = 0; i < tr; i++){
        if(adj[i].first != nn){
            ed[nn] = i;
            nn = adj[i].first;
            st[nn] = i;
        }
    }
    ed[nn] = tr;

    n *= m;

    stk[++r] = 1;
    while(r){
        int u = stk[r--];
        if(u == n)
            return 1;
        for(int i = st[u]; i < ed[u]; i++){
            if(!vis[adj[i].second]){
                stk[++r] = adj[i].second;
                vis[adj[i].second] = 1;
            }
        }
    }

    return 0;
}

#ifndef ONLINE_JUDGE
int main(){
    printf("%d", (int)can_escape(3, 4, {{0, 0, 0, 0, 0},
                  {0, 3, 10, 8, 14},
                  {0, 1, 11, 12, 12},
                  {0, 6, 2, 3, 9}}));
    
}
#endif