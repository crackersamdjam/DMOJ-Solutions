#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}

using namespace std;
typedef long long ll;
const int MM = 5e4+1, sz = 800;

int N, Q, ptr, c[MM], f[MM], lastv[MM], ans[MM], path[MM<<1], dep[MM], sp[17][MM];
vector<int> adj[MM];
bool in[MM];
multiset<ll> ele, dif;

struct qry{
   int l, r, id, lca;
} q[MM];

void dfs(int cur, int pre){
    
    f[cur] = ptr;
    sp[0][cur] = pre;
    path[ptr++] = cur;
    
    for(int u: adj[cur]){
        if(u ^ pre){
            dep[u] = dep[cur]+1;
            dfs(u, cur);
        }
    }
    
    lastv[cur] = ptr;
    path[ptr++] = cur;
}

inline void up(int p){
    int v = c[p];
    if(!in[p]){
        ele.insert(v);
        auto itr = ele.lower_bound(v);
        
        ll h = *++itr, l = *----itr;
        
        dif.erase(dif.lower_bound(h-l));
        
        dif.insert(h-v);
        dif.insert(v-l);
    }
    else{
        auto itr = ele.lower_bound(v);
        ll h = *++itr, l = *----itr;
        
        dif.erase(dif.lower_bound(h-v));
        dif.erase(dif.lower_bound(v-l));
        dif.insert(h-l);
        
        ele.erase(++itr);
    }
    
    in[p] ^= 1;
}

inline int lca(int a, int b){
    if(dep[a] < dep[b]){
        int d = b;
        b = a;
        a = d;
    }
    for(int i = 16; i >= 0; i--){
        if(~sp[i][a] && (dep[sp[i][a]] >= dep[b]))
            a = sp[i][a];
    }
    if(a == b)
        return a;
    for(int i = 16; i >= 0; i--){
        if(~sp[i][a] && ~sp[i][b] && (sp[i][a] ^ sp[i][b])){
            a = sp[i][a];
            b = sp[i][b];
        }
    }
    return sp[0][a];
}

int main(){
    
    scan(N, Q);
    
    for(int i = 1; i <= N; i++)
        scan(c[i]);
    
    for(int i = 0,a,b; i < N-1; i++){
        scan(a, b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    memset(sp, -1, sizeof sp);
    
    dfs(1, -1);
    
    for(int i = 1; i < 17; i++){
        for(int j = 0; j < 2*N; j++)
            if(~sp[i-1][j])
                sp[i][j] = sp[i-1][sp[i-1][j]];
    }
    
    lastv[1] = 0;
    
    for(int i = 0,a,b; i < Q; i++){
        scan(a, b);
        if(f[a] > f[b]){
            int d = b;
            b = a;
            a = d;
        }
        
        int rt = lca(a, b);
        
        if(rt == a || rt == b)
            q[i] = {f[a], f[b], i, 0};
        else
            q[i] = {lastv[a], f[b], i, rt};
    }
    
    sort(q, q+Q, [](const qry &x, const qry &y){
        int f = x.l/sz, s = y.l/sz;
        if(f^s)
            return f < s;
        return x.r < y.r;
    });
    
    ele.insert(-1e9);
    ele.insert(1e10);
    dif.insert(2e10);
    
    up(path[0]);
    
    for(int i = 0, l = 0, r = 0; i < Q; i++){
        while(l > q[i].l)
            up(path[--l]);
        
        while(r > q[i].r)
            up(path[r--]);
    
        while(r < q[i].r)
            up(path[++r]);
        
        while(l < q[i].l)
            up(path[l++]);
        
        if(q[i].lca)
            up(q[i].lca);
        
        ans[q[i].id] = *dif.begin();
        
        if(q[i].lca)
            up(q[i].lca);
        
    }
    
    for(int i = 0; i < Q; i++)
        print(ans[i]);
    
    return 0;
}