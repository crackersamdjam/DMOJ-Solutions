//next time, make us do lca as well
#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef pair<int, int> pii;
const int MM = 1001;

int n, m, qn, dis[MM], par[MM];
bool vis[MM];
vector<pii> adj[MM], adjr[MM];
priority_queue<pii, vector<pii>, greater<pii>> q;

void dfs(int c, int p){
    for(auto u: adjr[c]){
        if(u.first == p)
            continue;
        dis[u.first] = max(dis[c], u.second);
        dfs(u.first, c);
    }
}

int main(){
    
    scan(n, m, qn);
    
    for(int i = 0,a,b,c; i < m; i++){
        scan(a, b, c);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    memset(dis, 0x3f, sizeof dis);
    
    dis[1] = 0;
    q.push({0, 1});
    
    while(!q.empty()){
        
        int cur = q.top().second; q.pop();
        if(vis[cur])
            continue;
        vis[cur] = 1;
        
        for(auto e: adj[cur]){
            if(!vis[e.first] && e.second < dis[e.first]){
                dis[e.first] = e.second;
                par[e.first] = cur;
                q.push({e.second, e.first});
            }
        }
    }
    
    for(int i = 2; i <= n; i++){
        if(dis[i] != 0x3f3f3f3f){
            adjr[i].push_back({par[i], dis[i]});
            adjr[par[i]].push_back({i, dis[i]});
        }
    }
    
    for(int i = 0,a,b; i < qn; i++){
        scan(a, b);
        dis[a] = 0;
        dfs(a, 0);
        print(dis[b] == 0x3f3f3f3f? -1: dis[b]);
    }
    
    return 0;
}