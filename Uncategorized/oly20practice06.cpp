#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+2;

int n, sz[MM], ans[MM];
vector<int> adj[MM], rt;

//gets sizes and pushes centroid(s) into vec
int getsz(int cur, int pre){
    bool b = 1;
    sz[cur] = 1;
    for(int u: adj[cur]){
        if(u != pre){
            sz[cur] += getsz(u, cur);
            if(sz[u] > n/2)
                b = 0;
        }
    }
    if(b && ((n - sz[cur]) <= n/2))
        rt.emplace_back(cur);
    return sz[cur];
}

vector<pair<int, int>> v;
int sum, nx, cnt, in[MM];

void dfs(int cur, int pre, int par){
//    printf("%d %d %d %d %d %d\n", cur, sum, cnt, sz[cur], sz[par], nx);
    if(in[par]){
        if((n-(sum-sz[par]+nx)-sz[cur]) > n/2)
            ans[cur] = 1;
    }
    else{
        if((n-sum-sz[cur]) > n/2)
            ans[cur] = 1;
    }
    for(int u: adj[cur])
        if(u != pre)
            dfs(u, cur, par);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0,a,b; i < n-1; i++){
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    getsz(1, 0);
    int cent = rt[0];
    getsz(cent, 0);
    for(int i: adj[cent])
        v.emplace_back(sz[i], i);
    sort(v.rbegin(), v.rend());
    for(auto i: v){
        if((n-(sum+i.first) <= n/2)){
            nx = i.first;
            break;
        }
        sum += i.first;
        cnt++;
        in[i.second] = 1;
    }
    for(int i: adj[cent])
        dfs(i, cent, i);
    
    for(int i = 1; i <= n; i++){
        if(i == rt.front() || i == rt.back())
            cout<<"0\n";
        else
            cout<<cnt + ans[i]<<'\n';
    }
    
    return 0;
}