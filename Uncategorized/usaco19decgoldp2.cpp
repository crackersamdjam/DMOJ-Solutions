#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4,popcnt,abm,mmx,tune=native")

#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+1, LOG = 17;

int n, m, t[MM], cnt[MM];
bool ans[MM];
vector<int> adj[MM], pts[MM];
struct st{
    int a, b, i;
};
vector<st> q[MM];
int dep[MM], lca[LOG][MM];

int getlca(int u, int v){
    if(dep[u] < dep[v])
        swap(u, v);
    for(int i = LOG-1; i >= 0; i--){
        if((lca[i][u] != -1) && (dep[lca[i][u]] >= dep[v]))
            u = lca[i][u];
    }
    if(u == v)
        return u;
    for(int i = LOG-1; i >= 0; i--){
        if((lca[i][u] != -1) && (lca[i][v] != -1) && (lca[i][u] != lca[i][v])){
            u = lca[i][u];
            v = lca[i][v];
        }
    }
    return lca[0][u];
}

void dfs(int cur, int pre, int val){
    dep[cur] = dep[pre]+1;
    lca[0][cur] = pre;
    cnt[cur] = cnt[pre] + (t[cur] == val);
    for(int u: adj[cur]){
        if(u != pre)
            dfs(u, cur, val);
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> t[i];
        pts[t[i]].emplace_back(i);
    }
    for(int i = 0,a,b; i < n-1; i++){
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    
    for(int i = 0,a,b,c; i < m; i++){
        cin >> a >> b >> c;
        q[c].push_back({a, b, i});
    }
    
    memset(lca, -1, sizeof lca);
    dfs(1, 0, -1);
    for(int i = 1; i < LOG; i++){
        for(int j = 1; j <= n; j++){
            if(~lca[i-1][j])
                lca[i][j] = lca[i-1][ lca[i-1][j] ];
        }
    }
    
    for(int i = 1; i <= n; i++){
        if(pts[i].size() < 320){
            //loop
            for(auto p: q[i]){
                int l = getlca(p.a, p.b);
                for(int j: pts[i]){
                    //see if point j is between p.a and p.b
                    int la = getlca(p.a, j), lb = getlca(p.b, j);
                    if((la == l or lb == l) and (la == j or lb == j)){
                        ans[p.i] = 1;
                        break;
                    }
                }
            }
        }
        else{
            //dfs
            dfs(1, 0, i);
            for(auto p: q[i]){
                int l = getlca(p.a, p.b);
                if(cnt[p.a] + cnt[p.b] - 2*cnt[l] + (t[l] == i) > 0)
                    ans[p.i] = 1;
            }
        }
    }
    
    for(int i = 0; i < m; i++)
        cout << ans[i];
    cout << '\n';
    
    return 0;
}
// https://dmoj.ca/src/1825415 smh