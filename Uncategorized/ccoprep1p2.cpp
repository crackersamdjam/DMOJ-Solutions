#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MM = 505;

int n, dfn[MM], low[MM], t;
bool art[MM], vis[MM];
vector<pair<int, int>> adj[MM];

void dfs(int cur, int pre){
    dfn[cur] = low[cur] = ++t;
    int ch = 0;
    for(auto e: adj[cur]){
        int u = e.first, w = e.second;
        if(w == pre)
            continue;
    
        if(!dfn[u]){
            ch++;
            dfs(u, w);
    
            low[cur] = min(low[cur], low[u]);
        }
        else
            low[cur] = min(low[cur], dfn[u]);
    
        if(pre != -1 and low[u] >= dfn[cur])
            art[cur] = 1;
        if(pre == -1 and ch > 1)
            art[cur] = 1;
    }
}

int sz;
set<int> con;
void go(int cur){
//    cout<<"go "<<cur<<endl;
    assert(!art[cur]);
    vis[cur] = 1;
    sz++;
    for(auto e: adj[cur]){
        int u = e.first;
        if(art[u])
            con.insert(u);
        else if(!vis[u])
            go(u);
    }
}

int main(){
    while(1){
        memset(dfn, 0, sizeof dfn);
        memset(low, 0, sizeof low);
        memset(vis, 0, sizeof vis);
        memset(art, 0, sizeof art);
        t = 0;
        for(int i = 0; i < MM; i++)
            adj[i].clear();
        
        cin>>n;
        if(!n)
            break;
        
        for(int i = 0,a,b; i < n; i++){
            cin>>a>>b;
            adj[a].emplace_back(b, i);
            adj[b].emplace_back(a, i);
        }
        for(int i = 1; i < MM; i++){
            if(!dfn[i] and adj[i].size())
                dfs(i, -1);
        }
        int cnt = 0;
        ll ans = 1;
        for(int i = 1; i < MM; i++){
            if(adj[i].size() and !art[i] and !vis[i]){
//                cout<<"st "<<i<<endl;
                sz = 0;
                con.clear();
                
                go(i);
                if(con.size() == 0){
                    cnt += 2;
                    ans *= sz*(sz-1)/2;
                }
                if(con.size() == 1){
                    cnt++;
                    ans *= sz;
                }
            }
        }
        cout<<cnt<<' '<<ans<<'\n';
    }
}