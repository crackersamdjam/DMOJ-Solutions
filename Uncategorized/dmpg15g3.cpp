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
typedef long long ll;
const int MM = 2e5+2;

#define x first
#define y second

int n, lx, rx, ly, ry, sz[MM], tot, bit[MM];
vector<int> adj[MM];
vector<pii> all, path;
bool vis[MM];
char s[MM];
ll ans;

void update(int i, int v){
    for(i++; i < MM; i += i&-i)
        bit[i] += v;
}

int query(int i){
    if(i < 0)
        return 0;
    int ret = 0;
    for(i++; i; i -= i&-i)
        ret += bit[i];
    return ret;
}

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

void dfs(int cur, int pre, int cnta, int cntb){
    
    (s[cur] == 'K')? cnta++ : cntb++;
    path.push_back({cnta, cntb});
    all.push_back({cnta, cntb});
    
    if(cnta >= lx and cnta <= rx and cntb >= ly and cntb <= ry)
        ans += 2;
    
    for(int u: adj[cur]){
        if(u == pre || vis[u])
            continue;
        
        dfs(u, cur, cnta, cntb);
    }
}

void go(int root){
    
    getsz(root, -1);
    tot = sz[root];
    
    int cent = findcent(root, -1);
    int cx = (s[cent] == 'K'), cy = cx^1;
    all.clear();
    vis[cent] = 1;
    
    if(cx >= lx and cx <= rx and cy >= ly and cy <= ry)
        ans += 2;
    
    for(int u: adj[cent]){
        if(vis[u])
            continue;
        
        path.clear();
        dfs(u, 0, cx, cy);
        sort(path.begin(), path.end());
        int l = path.size()-1, r = path.size()-1;
        
        for(int i = 0; i < path.size(); i++){
            // (l, r]
            while(l >= 0 && path[i].x + path[l].x - cx >= lx)
                update(path[l--].y, 1);
            
            while(r > l && path[i].x + path[r].x - cx > rx)
                update(path[r--].y, -1);
            
            ans -= query(ry-(path[i].y - cy)) - query(ly-(path[i].y - cy)-1);
        }
        while(r > l)
            update(path[r--].y, -1);
    }
    
    sort(all.begin(), all.end());
    int l = all.size()-1, r = all.size()-1;
    
    for(int i = 0; i < all.size(); i++){
        
        while(l >= 0 && all[i].x + all[l].x - cx >= lx)
            update(all[l--].y, 1);
        
        while(r > l && all[i].x + all[r].x - cx > rx)
            update(all[r--].y, -1);
        
        ans += query(ry-(all[i].y - cy)) - query(ly-(all[i].y - cy)-1);
    }
    while(r > l)
        update(all[r--].y, -1);
    
    for(int u: adj[cent]){
        if(!vis[u])
            go(u);
    }
}

int main(){
    
    scanf("%d%d%d%d%d", &n, &lx, &rx, &ly, &ry);
    scanf("%s", s+1);
    
    for(int i = 0,a,b; i < n-1; i++){
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    all.reserve(n);
    path.reserve(n);
    
    go(1);
    
    print(ans/2);
    
    return 0;
}