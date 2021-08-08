#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1e5+1;

int n, q, ans[MM], dis[MM];
vector<int> adj[MM];
map<int, int> mp[MM];
map<pair<int, int>, int> vis;

int main(){
    
    scan(n);
    
    for(int i = 1,k,u; i <= n; i++){
        scan(k);
        for(int j = 0; j < k; j++){
            scan(u);
            adj[i].push_back(u);
            mp[i][u] = j;
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j: adj[i]){
            if(!vis[{i, j}]){
                int v = i, u = j;
                dis[u] = 0;
                
                while(1){
                    if(vis[{u, v}] >= 2)
                        break;
                    vis[{u, v}]++;
                    
                    int id = mp[u][v]-1;
                    if(id < 0) id += adj[u].size();
                    int nx = adj[u][id];
                    v = u;
                    u = nx;
                    
                    if(dis[u])
                        ans[u] = max(ans[u], dis[v]+1-dis[u]);
                    dis[u] = dis[v]+1;
                }
            }
        }
    }
    
    scan(q);
    int v;
    while(q--){
        scan(v);
        print(ans[v]);
    }
    
    
    return 0;
}