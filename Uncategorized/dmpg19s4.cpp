#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>

using namespace std;
const int MM = 1e5+2;

int N, M, Q;
unordered_map<string, int> mp;
string str[MM];
vector<int> adj[MM];
int dis[26][MM];
string pre[26][MM];
vector<int> each[26];
queue<pair<int, string>> q;

int main(){
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M >> Q;
    
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        mp[s] = i;
        str[i] = s;
        each[s[0]-'A'].push_back(i);
    }
    
    for(int i = 0,a,b; i < M; i++){
        string sa, sb;
        cin >> sa >> sb;
        a = mp[sa], b = mp[sb];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    memset(dis, 0x3f, sizeof dis);
    
    for(int k = 0; k < 26; k++){
        
        sort(each[k].begin(), each[k].end());
        
        for(int a: each[k]){
            dis[k][a] = 0;
            pre[k][a] = str[a];
            q.push({a, str[a]});
        }
        
        while(!q.empty()){
            int cur = q.front().first;
            q.pop();
            for(int u: adj[cur]){
                if(dis[k][cur]+1 < dis[k][u]){
                    dis[k][u] = dis[k][cur]+1;
                    pre[k][u] = pre[k][cur];
                    q.push({u, pre[k][cur]});
                }
                else if(dis[k][cur]+1 == dis[k][u] and pre[k][cur] < pre[k][u]){
                    pre[k][u] = pre[k][cur];
                    q.push({u, pre[k][cur]});
                }
            }
        }
    }
    
    for(int i = 0; i < Q; i++){
        string sa;
        char c;
        cin >> sa >> c;
        int a = mp[sa];
        c -= 'A';
        
        if(dis[c][a] == 0x3f3f3f3f){
            cout << "-1\n";
            continue;
        }
        
        cout << pre[c][a] << '\n';
    }
    
    return 0;
}