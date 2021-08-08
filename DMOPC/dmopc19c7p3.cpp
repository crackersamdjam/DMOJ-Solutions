#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MM = 1e6+5;

bool vis[MM];
int n, no[MM];
ll k, v[MM], sum;
vector<int> adj[MM], ans;

void dfs(int cur, int pre){
    if(no[cur]) return;
    sum += v[cur];
    ans.emplace_back(cur);
    if(sum >= k){
        cout<<ans.size()<<'\n';
        for(int i: ans)
            cout<<i<<' ';
        exit(0);
    }
    for(int u: adj[cur]){
        if(u != pre)
            dfs(u, cur);
    }

    sum -= v[cur];
    ans.pop_back();
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for(int i = 1; i <= n; i++){
        cin>>v[i];    
        if(v[i] >= k and v[i] <= k+k){
            cout<<"1\n"<<i;
            exit(0);
        }
        else if(v[i] > k+k)
            no[i] = 1;
    }
    for(int i = 0,a,b; i < n-1; i++){
        cin>>a>>b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i])
            dfs(i, 0);
    }
    cout<<-1;
    
    return 0;
}