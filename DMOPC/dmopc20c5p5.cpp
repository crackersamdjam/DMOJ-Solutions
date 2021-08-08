#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 2e5+2, LOG = 18;

int n, q, dep[MM], sp[LOG][MM], t, f[MM], s[MM], bit[MM<<1], on[MM];
vector<int> adj[MM];

void update(int i, int v){
    if(!i) return;
    for(; i < (MM<<1); i += i&-i)
        bit[i] += v;
}

int query(int i){
    int ret = 0;
    for(; i; i -= i&-i)
        ret += bit[i];
    return ret;
}

int getlca(int u, int v){
    if(dep[u] < dep[v])
        swap(u, v);
    for(int i = LOG-1; i >= 0; i--){
        if((~sp[i][u]) && (dep[sp[i][u]] >= dep[v]))
            u = sp[i][u];
    }
    if(u == v)
        return u;
    for(int i = LOG-1; i >= 0; i--){
        if((~sp[i][u]) && (~sp[i][v]) && (sp[i][u] != sp[i][v])){
            u = sp[i][u];
            v = sp[i][v];
        }
    }
    return sp[0][u];
}

void dfs(int cur, int pre){
    dep[cur] = dep[pre]+1;
    sp[0][cur] = pre;
    f[cur] = ++t;
    for(int u: adj[cur]){
        if(u != pre)
            dfs(u, cur);
    }
    s[cur] = ++t;
}

int main(){
    scan(n, q);
    for(int i = 0,a,b; i < n-1; i++){
        scan(a, b);
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
        assert(a > 0 and a <= n);
        assert(b > 0 and b <= n);
    }
    
    memset(sp, -1, sizeof sp);
    
    dfs(1, 0);
    
    for(int i = 1; i < LOG; i++){
        for(int j = 1; j <= n; j++){
            if(~sp[i-1][j]){
                sp[i][j] = sp[i-1][ sp[i-1][j] ];
            }
        }
    }
    
    //for(int i = 1; i <= n; i++)
      //  assert(~sp[0][i]);
    
    for(int z = 0,op,a,b; z < q; z++){
        scan(op, a);
        assert(a > 0 and a <= n);
        if(op == 1){
            int v = on[a] ? -1 : 1;
            on[a] ^= 1;
            a = sp[0][a]; //update parent
            update(f[a], v);
            update(s[a], -v);
        }
        else{
            scan(b);
            assert(b > 0 and b <= n);
            int l = getlca(a, b), ans;
            if(f[a] > f[b])
                swap(a, b);
            
            ans = query(f[b]) + query(f[a]) - query(f[l]) - query(f[l]-1) + on[l] + on[sp[0][l]];
            //down to b, down to a, subtract but also include f[l]'s value (its children), on[l], par of l
            
            print(ans);
        }
    }
    
    return 0;
}