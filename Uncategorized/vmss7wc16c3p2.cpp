#include <bits/stdc++.h>
using namespace std;
#define MM 2005
vector<int> adj[MM];
bool vis[MM];
int main() {
    int N,M,A,B;
    scanf("%d%d%d%d",&N,&M,&A,&B);
    for(int i = 0,x,y; i < M; i++){
        scanf("%d%d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue<int> q; q.push(A); vis[A] = true;// bool b = false;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int u: adj[cur]){
            //if(u == B){b = true; break;}
            if(!vis[u]){
                vis[u] = true;
                q.push(u);
            }
        }
        //if(b) break;
    }
    printf(vis[B]?"GO SHAHIR!":"NO SHAHIR!");
    return 0;
}