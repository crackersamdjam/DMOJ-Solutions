#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4,popcnt,abm,mmx,tune=native")

#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))

const int MM = 1e5+1, LOG = 17;

int n, q, r, dep[MM], lca[LOG][MM], mx[LOG][MM], mn[LOG][MM], x[MM], y[MM], p[MM];
std::vector<int> adj[MM];

int getlca(int u, int v){
    if(dep[u] < dep[v]){
        int c = u;
        u = v;
        v = c;
    }
    for(int i = LOG-1; i >= 0; i--){
        if((lca[i][u] != -1) && (dep[lca[i][u]] >= dep[v]))
            u = lca[i][u];
    }
    if(u == v)
        return u;
    for(int i = LOG-1; i >= 0; i--){
        if((lca[i][u] != -1) && (lca[i][v] != -1) && (lca[i][u] != lca[i][v])){
            u = lca[i][u];
            v = lca[i][v];
        }
    }
    return lca[0][u];
}

int query(int a, int b){
    int lcan = getlca(a, b), ret = mx[0][lcan]; //include highest
    for(int i = LOG-1; i >= 0; i--){
        if(dep[a] >= dep[lcan] + (1<<i)){
            if(mx[i][a] > ret)
                ret = mx[i][a];
            a = lca[i][a];
        }
    }
    for(int i = LOG-1; i >= 0; i--){
        if(dep[b] >= dep[lcan] + (1<<i)){
            if(mx[i][b] > ret)
                ret = mx[i][b];
            b = lca[i][b];
        }
    }
    return ret;
}

int q2(int a, int b){
    int lcan = getlca(a, b), ret = 1e9;
    for(int i = LOG-1; i >= 0; i--){
        if(dep[a] >= dep[lcan] + (1<<i)){
            if(mn[i][a] < ret)
                ret = mn[i][a];
            a = lca[i][a];
        }
    }
    for(int i = LOG-1; i >= 0; i--){
        if(dep[b] >= dep[lcan] + (1<<i)){
            if(mn[i][b] < ret)
                ret = mn[i][b];
            b = lca[i][b];
        }
    }
    return ret;
}

int jump(int a, int dis){
    int ret = 0;
    for(int i = LOG-1; i >= 0; i--){
        if(dep[a] >= dis + (1<<i)){
            if(mx[i][a] > ret)
                ret = mx[i][a];
            a = lca[i][a];
        }
    }
    if(mx[0][a] > ret)
        ret = mx[0][a];
    //last one too
    return ret;
}

int id(int a, int dis){
    for(int i = LOG-1; i >= 0; i--){
        if(dep[a] >= dis + (1<<i))
            a = lca[i][a];
    }
    return a;
}

void dfs(int cur, int pre){
    dep[cur] = dep[pre]+1;
    lca[0][cur] = pre;
    mx[0][cur] = p[cur];
    for(int u: adj[cur]){
        if(u != pre)
            dfs(u, cur);
    }
}

int main(){
    memset(lca, -1, sizeof lca);
    memset(mn, 0x3f, sizeof mn);
    
    scan(n, q, r);
    for(int i = 1; i <= n; i++)
        scan(p[i]);
    for(int i = 0,a,b; i < n-1; i++){
        scan(a, b);
        x[i] = a, y[i] = b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    dfs(1, 0);
    
    while(r--){
        int i, t;
        scan(i, t);
        t--;
        if(dep[x[t]] < dep[y[t]])
            x[t] = y[t];
        mn[0][x[t]] = i;
    }
    
    for(int i = 1; i < LOG; i++){
        for(int j = 0; j <= n; j++){
            if(~lca[i-1][j]){
                lca[i][j] = lca[i-1][ lca[i-1][j] ];
                mx[i][j] = max(mx[i-1][j], mx[i-1][ lca[i-1][j] ]);
                mn[i][j] = min(mn[i-1][j], mn[i-1][ lca[i-1][j] ]);
            }
        }
    }
    
    for(int t = 1,a,b,k; t <= q; t++){
        scan(a, b, k);
        if(q2(a, b) < t || query(a, b) < k){
            print(-1);
            continue;
        }
        int l = getlca(a, b);
        
        if(jump(a, dep[l]) >= k){
            int lo = dep[l], mid, hi = dep[a];
            while(lo <= hi){
                mid = (lo+hi)/2;
                if(jump(a, mid) >= k)
                    lo = mid+1;
                else
                    hi = mid-1;
            }
            print(id(a, hi));
        }
        else{
            int lo = dep[l], mid, hi = dep[b];
            while(lo <= hi){
                mid = (lo+hi)/2;
                if(query(id(b, mid), l) >= k)
                    hi = mid-1;
                else
                    lo = mid+1;
            }
            print(id(b, lo));
        }
    }
    
    return 0;
}