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
const int MM = 4e5+5;

int n, q, a[MM], b[MM], c[MM], f[MM], s[MM], ind, dep[MM], bit[MM], bit2[MM], sz[MM];
vector<int> adj[MM];

void update(int i, int v){
    for(; i < MM; i += i&-i)
        bit[i] += v;
}
int query(int i){
    int ret = 0;
    for(; i; i -= i&-i)
        ret += bit[i];
    return ret;
}
void update2(int i, int v){
    for(; i < MM; i += i&-i)
        bit2[i] += v;
}
int query2(int i){
    int ret = 0;
    for(; i; i -= i&-i)
        ret += bit2[i];
    return ret;
}

void dfs(int cur, int pre){
    f[cur] = ++ind;
    dep[cur] = dep[pre]+1;
    sz[cur] = 1;
    for(int u: adj[cur])
        if(u != pre){
            dfs(u, cur);
            sz[cur] += sz[u];
        }
    s[cur] = ++ind;
}

int main(){
    scan(n, q);
    for(int i = 0; i < n-1; i++){
        scan(a[i], b[i]);
        adj[a[i]].emplace_back(b[i]);
        adj[b[i]].emplace_back(a[i]);
    }
    dep[0] = -1;
    dfs(1, 0);
    for(int i = 0; i < n-1; i++){
        if(dep[a[i]] > dep[b[i]]){
            //going up
            c[i] = 1;
            update(f[a[i]], 1);
            update2(f[a[i]], 1);
            update2(s[a[i]], -1);
        }
        else{
            //going down
            swap(a[i], b[i]);
            c[i] = 0;
        }
    }
    for(int i = 0,op,u; i < q; i++){
        scan(op, u);
        if(op == 1){
            int in = query(s[u]) - query(f[u]);
            int ans = in; //those up need to go down
            int along = query2(f[u]); //those that go up correctly
            ans += dep[u] - along; //those that are down
            int out = query(ind) - in - along; //those about that go up
            ans += out;
            print(ans);
        }
        else{
            u--;
            if(c[u]){
                c[u] = 0;
                u = a[u];
                update(f[u], -1);
                update2(f[u], -1);
                update2(s[u], 1);
            }
            else{
                c[u] = 1;
                u = a[u];
                update(f[u], 1);
                update2(f[u], 1);
                update2(s[u], -1);
            }
        }
    }
    
    return 0;
}