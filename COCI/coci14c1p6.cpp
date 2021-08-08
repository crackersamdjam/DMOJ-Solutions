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
typedef pair<int, int> pii;
const int MM = 5e5+1;

int n, k, st, par[MM];
vector<pii> adj[MM], adjr[MM];
ll dis[MM], dis2[MM], dis3[MM], sum, maxd, ed;
ll *ptr = dis;
bool v[MM];

void prune(int cur, int pre){
    
    if(v[cur] && dis[cur] > maxd){
        maxd = dis[cur];
        ed = cur;
    }
    
    for(auto u: adj[cur]){
        if(u.first == pre)
            continue;
        dis[u.first] = dis[cur] + u.second;
        prune(u.first, cur);
        v[cur] |= v[u.first];
        if(v[u.first]){
            adjr[cur].push_back(u);
            adjr[u.first].push_back({cur, u.second});
            sum += u.second;
        }
    }
}

void prop(int cur, int pre){
    if(v[cur]){
        dis3[cur] = 0;
        par[cur] = cur;
    }
    for(auto u: adj[cur]){
        if(u.first == pre)
            continue;
        dis3[u.first] = dis3[cur] + u.second;
        par[u.first] = par[cur];
        prop(u.first, cur);
    }
}

void dfs(int cur, int pre){
    
    if(ptr[cur] > maxd){
        maxd = ptr[cur];
        ed = cur;
    }
    for(auto u: adjr[cur]){
        if(u.first == pre)
            continue;
        ptr[u.first] = ptr[cur] + u.second;
        dfs(u.first, cur);
    }
}

int main(){
    
    scan(n, k);
    
    for(int i = 0,a,b,c; i < n-1; i++){
        scan(a, b, c);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    while(k--){
        int m;
        scan(m);
        v[m] = 1;
        st = m;
    }
    
    prune(st, 0);
    prop(st, 0);
    
    maxd = ptr[ed] = 0;
    dfs(ed, 0);
    
    ptr = dis2;
    dfs(ed, 0);
    
    for(int i = 1; i <= n; i++){
        int p = par[i];
        print(sum*2 + dis3[i] - max(dis[p], dis2[p]));
    }
    
    return 0;
}