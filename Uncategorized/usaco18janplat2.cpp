#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int MM = 7e4+1;

int n, cnt[MM], sz[MM], dep[MM], tot, leaf[MM];
vector<int> adj[MM];
bool vis[MM];
vector<pii> rt, bl;
//root, block

int getsz(int cur, int pre){
    sz[cur] = 1;
    for(int u: adj[cur]){
        if(u != pre && !vis[u])
            sz[cur] += getsz(u, cur);
    }
    return sz[cur];
}

int findcent(int cur, int pre){
    for(int u: adj[cur]){
        if(!vis[u] && u != pre && sz[u]*2 > tot)
            return findcent(u, cur);
    }
    return cur;
}

void dfs1(int cur, int pre){
    dep[cur] = dep[pre]+1;
    rt.emplace_back(dep[cur], cur);
    bl.emplace_back(leaf[cur] - dep[cur], adj[cur].size());
    for(int u: adj[cur]){
        if(u == pre || vis[u])
            continue;
        dfs1(u, cur);
    }
}

void run(int st, int pre, int f){
    rt.clear();
    bl.clear();
    dfs1(st, pre);
    sort(rt.begin(), rt.end());
    sort(bl.begin(), bl.end());
    //dep[u] >= leaf[v] - dep[v]
    //dep[u]+dep[v] >= leaf[v]
    //topar[v] >= leaf[v] when u is subtree
    
    int l = 0, sum = 0;
    for(auto i: rt){
        while(l < bl.size() and i.first >= bl[l].first)
            sum += 2-bl[l++].second;
        cnt[i.second] += sum*f;
    }
}

void go(int root){
    
    tot = getsz(root, -1);
    if(tot == 1)
        return;
    int cent = findcent(root, -1);
    vis[cent] = 1;
    
    run(cent, 0, 1); //so that dep[cent] = 0
    
    for(int u: adj[cent]){
        if(vis[u])
            continue;
        // subtract overcount for each subtree (if necessary)
        run(u, cent, -1); //so that dep[u] = 1
    }
    
    for(int u: adj[cent]){
        if(!vis[u])
            go(u);
    }
}

queue<int> q;

int main(){
    //freopen("in.txt", "r", stdin);
    cin.sync_with_stdio(0);
    cin.tie(0);
    dep[0] = -1;
    cin >> n;
    for(int i = 0,a,b; i < n-1; i++){
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    
    memset(leaf, 0x3f, sizeof leaf);
    for(int i = 1; i <= n; i++){
        if(adj[i].size() == 1){
            leaf[i] = 0;
            q.push(i);
        }
    }
    while(!q.empty()){
        int c = q.front(); q.pop();
        for(int u: adj[c]){
            if(leaf[c]+1 < leaf[u]){
                leaf[u] = leaf[c]+1;
                q.push(u);
            }
        }
    }
    
    go(1);
    
    for(int i = 1; i <= n; i++)
        cout << cnt[i] << '\n';
    
    return 0;
}