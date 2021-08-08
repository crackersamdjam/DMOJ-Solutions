#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
const int MM = 1e5+2, LOG = 18;

struct pp{
    int f, s;
};

int n, m, dep[MM], sp[LOG][MM];
pp val[LOG][MM];
vector<pair<int, int>> adj[MM];
bool used[MM];

int getlca(int u, int v){
    if(dep[u] < dep[v])
        swap(u, v);
    for(int i = LOG-1; i >= 0; i--){
        if(~sp[i][u] && (dep[sp[i][u]] >= dep[v]))
            u = sp[i][u];
    }
    if(u == v)
        return u;
    for(int i = LOG-1; i >= 0; i--){
        if(~sp[i][u] && ~sp[i][v] && (sp[i][u] != sp[i][v])){
            u = sp[i][u];
            v = sp[i][v];
        }
    }
    return sp[0][u];
}

// max and second max
pp query(int a, int b){
    int lcan = getlca(a, b);
    pp ret = {-2, -3};
    for(int i = LOG-1; i >= 0; i--){
        if(dep[a] >= dep[lcan] + (1<<i)){
            
            vector<int> v = {val[i][a].f, val[i][a].s, ret.f, ret.s};
            sort(all(v));
            v.erase(unique(v.begin(), v.end()), v.end());
            sort(all(v));
//            assert(v.size() > 1);
            ret.f = v.back();
            v.pop_back();
            ret.s = v.back();
            
            a = sp[i][a];
        }
    }
    for(int i = LOG-1; i >= 0; i--){
        if(dep[b] >= dep[lcan] + (1<<i)){
            
            vector<int> v = {val[i][b].f, val[i][b].s, ret.f, ret.s};
            sort(all(v));
            v.erase(unique(v.begin(), v.end()), v.end());
            sort(all(v));
//            assert(v.size() > 1);
            ret.f = v.back();
            v.pop_back();
            ret.s = v.back();
            
            b = sp[i][b];
        }
    }
    return ret;
}

void dfs(int cur, int pre, int w){
    dep[cur] = dep[pre]+1;
    sp[0][cur] = pre;
    val[0][cur].f = w;
    val[0][cur].s = -1;
    for(auto e: adj[cur]){
        if(e.first != pre)
            dfs(e.first, cur, e.second);
    }
}

struct edge{
    int a, b, c;
    bool operator<(const edge &o) const{
        return c < o.c;
    }
} e[MM];

ll sum, best = LLONG_MAX;
int par[MM], cnt;

int find(int x){
    while(x != par[x])
        x = par[x], par[x] = par[par[x]];
    return x;
}

int main(){
    
    scan(n, m);
    for(int i = 0; i < m; i++)
        scan(e[i].a, e[i].b, e[i].c);
    sort(e, e+m);
    for(int i = 1; i <= n; i++)
        par[i] = i;
    for(int i = 0; i < m; i++){
        int fa = find(e[i].a), fb = find(e[i].b);
        if(fa != fb){
            par[fa] = fb;
            sum += e[i].c;
            adj[e[i].a].emplace_back(e[i].b, e[i].c);
            adj[e[i].b].emplace_back(e[i].a, e[i].c);
            used[i] = 1;
            cnt++;
        }
    }
    
    if(cnt != n-1)
        return print(-1), 0;
    
    memset(sp, -1, sizeof sp);
    dfs(1, 0, -1);
    
    for(int i = 1; i < LOG; i++){
        for(int j = 1; j <= n; j++){
            int u = sp[i-1][j];
            if(~u){
                sp[i][j] = sp[i-1][u];
                vector<int> v = {val[i-1][j].f, val[i-1][j].s, val[i-1][u].f, val[i-1][u].s};
                sort(all(v));
                v.erase(unique(v.begin(), v.end()), v.end());
                sort(all(v));
//                assert(v.size() > 1);
                val[i][j].f = v.back();
                v.pop_back();
                val[i][j].s = v.back();
            }
        }
    }
    
    for(int i = 0; i < m; i++){
        if(used[i])
            continue;
        pp v = query(e[i].a, e[i].b);
        if(v.f == e[i].c)
            v.f = v.s;
        if(v.f <= 0)
            continue;
        assert(v.f < e[i].c);
        best = min(best, sum + e[i].c - v.f);
    }
    
    if(best == LLONG_MAX)
        print(-1);
    else
        print(best);
    
    return 0;
}