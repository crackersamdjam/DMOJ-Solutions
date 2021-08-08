#include <bits/stdc++.h>
using namespace std;
const int MM = 1005;

int n, m, vis[MM], ad = 1001, bt[MM][MM*2], pre, ass[MM], v1[MM], v2[MM];
bool dp[MM][MM*2], last[MM][MM*2], NO;
vector<int> adj[MM];
char out[MM];
vector<pair<int, int>> v[MM][2];

int dfs(int cur, int id, int val){
    int ret = val ? 1 : -1;
    ass[cur] = val;
    vis[cur] = id;
    v[pre][id-1].emplace_back(cur, val);
    for(int u: adj[cur]){
        if(vis[u] != id){
            vis[u] = id;
            ret += dfs(u, id, !val);
        }
        else if(ass[u] == ass[cur])
            NO = 1;
    }
    return ret;
}

int main(){
    
    cin >> n >> m;
    for(int i = 0,a,b; i < m; i++){
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            pre++;
            v1[pre] = dfs(i, 1, 0), v2[pre] = dfs(i, 2, 1);
            //so lex min is off
        }
    }
    
    dp[pre+1][ad] = 1;
    //dp backward to get lex min
    for(int i = pre; i; i--){
        for(int j = 0; j < 2000; j++){
            if(j-v1[i] > 0 and j-v1[i] < 2000 and dp[i+1][j-v1[i]]){
                dp[i][j] = 1;
                last[i][j] = 0;
                bt[i][j] = j-v1[i];
            }
        }
        for(int j = 0; j < 2000; j++){
            if(j-v2[i] > 0 and j-v2[i] < 2000 and dp[i+1][j-v2[i]] and !dp[i][j]){
                dp[i][j] = 1;
                last[i][j] = 1;
                bt[i][j] = j-v2[i];
            }
        }
    }
    
    if(NO){
        cout << "-1";
        return 0;
    }
    
    int val = 1e9;
    string best = "3";
    for(int k = 0; k < 2000; k++){
        if(dp[1][k]){
            //get string and compare
            int ans = k;
            string s; s.resize(n);
            
            for(int i = 1; i <= pre; i++){
                for(auto p: v[i][last[i][ans]]){
                    s[p.first-1] = '1'+p.second;
                }
                ans = bt[i][ans];
            }
            
            if(abs(k-ad) < val){
                val = abs(k-ad);
                best = s;
            }
            else if(abs(k-ad) == val)
                best = min(best, s);
        }
    }
    
    cout << best << '\n';
    
    return 0;
}