#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
const int MM = 1e5+1, LOG = 20;

int n, m, q, rt;
bool st[MM];
int dep[MM], sp[LOG][MM];
ll val[LOG][MM], dis[MM];
vector<pair<int, ll>> adj[MM];

int getlca(int u, int v){
    if(dep[u] < dep[v])
        swap(u, v);
    //u gets jumped up
    for(int i = LOG-1; i >= 0; i--){
        if(~sp[i][u] && (dep[sp[i][u]] >= dep[v]))
            u = sp[i][u];
    }
    //now should be on same level
    if(u == v)
        return u;
    for(int i = LOG-1; i >= 0; i--){
        if(~sp[i][u] && ~sp[i][v] && (sp[i][u] != sp[i][v])){
            u = sp[i][u];
            v = sp[i][v];
        }
    }
    return sp[0][u];
    //return direct parent
}

ll query(int a, int b){
    int lcan = getlca(a, b);
    ll ret = LLONG_MAX/2;
    for(int i = LOG-1; i >= 0; i--){
        if(dep[a] >= dep[lcan] + (1<<i)){
            ret = min(ret, val[i][a]);
            a = sp[i][a];
        }
    }
    for(int i = LOG-1; i >= 0; i--){
        if(dep[b] >= dep[lcan] + (1<<i)){
            ret = min(ret, val[i][b]);
            b = sp[i][b];
        }
    }
    // cout<<"now at "<<a<<' '<<b<<' '<<ret<<endl;
    return ret;
}

ll dp[MM];

void dfs(int cur, int pre, ll w){
    dep[cur] = dep[pre]+1;
    dis[cur] = dis[pre]+w;
    dp[cur] = st[cur] ? 0: LLONG_MAX/2;

    sp[0][cur] = pre;

    for(auto e: adj[cur]){
        int u = e.first;
        if(u != pre){
            dfs(u, cur, e.second);
            dp[cur] = min(dp[cur], dp[u]+e.second);
        }
    }
    //best dp from below
    if(st[cur]){
        dp[cur] = 0;
    }
    val[0][cur] = dp[cur]-dis[cur];
    // cout<<"ins "<<cur<<' '<<val[0][cur]<<endl;
}

void dfs2(int cur, int pre, ll w){
    dp[cur] = min(dp[cur], dp[pre]+w);
    for(auto e: adj[cur]){
        int u = e.first;
        if(u != pre){
            dfs(u, cur, e.second);
        }
    }
}

int x[MM], y[MM];

int main(){
    memset(val, 0x3f, sizeof val);
    memset(dp, 0x3f, sizeof dp);
    memset(sp, -1, sizeof sp);
    scan(n, m, q, rt);
    
    for(int i = 0,a,b,c; i < n-1; i++){
        scan(a, b, c);
        x[i+1] = a, y[i+1] = b;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }

    while(m--){
        int a;
        scan(a);
        st[a] = 1;
        // cout<<"st "<<a<<endl;
    }

    dfs(rt, 0, 0);
    
    for(int i = 1; i < LOG; i++){
        for(int j = 0; j <= n; j++){
            if(~sp[i-1][j]){
                sp[i][j] = sp[i-1][ sp[i-1][j] ];
                val[i][j] = min(val[i-1][j], val[i-1][ sp[i-1][j] ]);
            }
        }
    }

    while(q--){
        int i, a;
        scan(i, a);
        if(dep[x[i]] < dep[y[i]])
            swap(x[i], y[i]);
        //x[i] is deeper

        int lca = getlca(x[i], a);
        // print(x[i], lca, a);
        if(lca != x[i]){
            puts("escaped");
            continue;
        }

        ll ans = min(dp[a], query(y[i], a)) + dis[a];
        // cout<<"qu "<<y[i]<<endl;
        // cout<<"cmp "<<dp[a]<<' '<<query(y[i], a)<<endl;

        if(ans > 1e14)
            puts("oo");
        else
            print(ans);
    }
    
    return 0;
}