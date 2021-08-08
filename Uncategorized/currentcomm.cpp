#define ONLINE_JUDGE

#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

#ifndef ONLINE_JUDGE
template<typename T>
void printerr(T a){std::cout<<a<<std::endl;}
template<typename T,typename... Args>
void printerr(T a, Args... args) {std::cout<<a<<' ',printerr(args...);}
#else
template<typename... Args>
void printerr(Args... args){}
#endif

using namespace std;
const int MM = 1e5+2, LOG = 20;

int n, k, dif[MM], f[MM], s[MM], lca[20][MM], dep[MM];
vector<int> adj[MM];

void dfsa(int cur, int pre){
    lca[0][cur] = pre;
    dep[cur] = dep[pre]+1;
    for(int u: adj[cur]){
        if(u != pre)
            dfsa(u, cur);
    }
}

int getlca(int u, int v){
    if(dep[u] < dep[v])
        swap(u, v);
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

bool res;

int dfsb(int cur, int pre){
    for(int u: adj[cur]){
        if(u != pre)
            dif[cur] += dfsb(u, cur);
    }
    if(dif[cur] > 1)
        res = 0;
    printerr("dif", cur, dif[cur]);
    return dif[cur];
}

bool run(int r){
    memset(dif, 0, sizeof dif);
    printerr("run", r);
    res = 1;
    for(int i = 0; i < r; i++){
        dif[f[i]]++, dif[s[i]]++;
        dif[getlca(f[i], s[i])] -= 2;
    }
    assert(!dfsb(1, 0));
    return res;
}

int main(){
    
    scan(n, k);
    
    for(int i = 0,a,b; i < n-1; i++){
        scan(a, b);
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    
    memset(lca, -1, sizeof lca);
    
    dfsa(1, 0);
    
    for(int i = 1; i < LOG; i++){
        for(int j = 1; j <= n; j++){
            if(~lca[i-1][j])
                lca[i][j] = lca[i-1][ lca[i-1][j] ];
        }
    }
    
    for(int i = 0; i < k; i++)
        scan(f[i], s[i]);
    
    int l = 1, m, r = k;
    while(l <= r){
        m = (l+r)/2;
        if(run(m))
            l = m+1;
        else
            r = m-1;
    }
    
    print(r);
    
    return 0;
}