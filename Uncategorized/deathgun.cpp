#include <bits/stdc++.h>
#define MM 902
using namespace std;
int M,cnt,in[MM];
bool vis[MM];
vector<int> adj[MM];
unordered_map<string, int> mp;
string names[MM], as, bs;
priority_queue<int, vector<int>, greater<int>> q;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> M;
    for(int i = 0,a,b; i < M; i++){
        cin >> as >> bs;
        if(!(a = mp[as])){
            a = mp[as] = ++cnt;
            names[a] = as;
        }
        if(!(b = mp[bs])){
            b = mp[bs] = ++cnt;
            names[b] = bs;
        }
        adj[b].push_back(a);
        in[a]++;
    }
    for(int i = 1; i <= cnt; i++){
        if(!in[i]){
            vis[i] = 1;
            q.push(i);
        }
    }
    while(!q.empty()){
        int cur = q.top(); q.pop();
        cout << names[cur] << '\n';
        for(auto &u: adj[cur]){
            if(!vis[u])
                in[u]--;
        }
        for(int u = 1; u <= cnt; u++){
            if(!vis[u] && !in[u]){
                vis[u] = 1;
                q.push(u);
            }
        }
    }
    return 0;
}