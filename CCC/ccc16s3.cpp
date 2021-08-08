#include <bits/stdc++.h>
using namespace std;
const int MM = 100001;

int N, M, start, node, dist, dis[MM], sum;
bool pho[MM];
vector<int> adj[MM], adjr[MM];

void dfs(int cur, int pre){
    
    if(pho[cur] && dis[cur] > dist){
        dist = dis[cur];
        node = cur;
    }
    
    for(int u: adj[cur]){
        if(u == pre)
            continue;
        
        dis[u] = dis[cur]+1;
        dfs(u, cur);
        
        pho[cur] |= pho[u];
    }
    
    if(pho[cur] && pre != -1){
        adjr[cur].push_back(pre);
        adjr[pre].push_back(cur);
        sum++;
    }
}

void dfs2(int cur, int pre){
    
    if(dis[cur] > dist)
        dist = dis[cur];
    
    for(int u: adjr[cur]){
        if(u == pre)
            continue;
        
        dis[u] = dis[cur]+1;
        dfs2(u, cur);
    }
}

int main(){
    
    scanf("%d%d", &N, &M);
    
    for(int i = 0,m; i < M; i++){
        scanf("%d", &m);
        pho[m] = 1;
        start = m;
    }
    
    for(int i = 0,a,b; i < N-1; i++){
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(start, -1);
    
    dist = dis[node] = 0;
    dfs2(node, -1);
    
    printf("%d\n", sum*2-dist);
    
    return 0;
}