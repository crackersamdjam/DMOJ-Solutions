#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef long long ll;
const int MM = 252;

int l, w, n;
ll x[MM], y[MM];
vector<int> adj[MM];
int vis[MM], vis2[MM];

#define sq(x) (x)*(x)

ll dis(int i, int j){
    return sq(x[i]-x[j]) + sq(y[i]-y[j]);
}

int st = 250, ed = 251;

void dfs(int i){
    if(i == ed){
        vis[ed]++;
        return;
    }
    if(vis[i])
        return;
    vis2[i] = vis[i] = 1;
    for(int u: adj[i])
        dfs(u);
}

int main(){
    
    scan(l, w, n);
    
    for(int i = 0; i < n; i++){
        scan(x[i], y[i]);
        for(int j = 0; j < i; j++){
            if(dis(i, j) <= sq(200)){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
        if(y[i] <= 100)
            adj[st].push_back(i);
        if(y[i] + 100 >= w)
            adj[i].push_back(ed);
    }
    
    int ans = 0;
    
    for(int u: adj[st]){
        if(vis2[u])
            continue;
        memset(vis, 0, sizeof vis);
        dfs(u);
        ans += vis[ed];
    }
    
    print(ans);
    
    return 0;
}