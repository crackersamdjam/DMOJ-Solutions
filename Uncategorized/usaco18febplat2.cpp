#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1e5+1, LOG = 18;

void init(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
    #endif
}

int q, dep[MM], lca[LOG][MM], t;

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

int dist(int u, int v){
    return dep[u] + dep[v] - 2*dep[getlca(u, v)];
}

int a[MM], b[MM], mx[MM], id[MM];

int main(){
    init();
    scan(q);
    while(q--){
        int u;
        if(gc == 'B'){
            gc;
            scan(u);
            t++;
            if(u == -1)
                id[t] = a[t] = b[t] = t;
            else
                dep[t] = dep[u]+1, id[t] = id[u];
            lca[0][t] = u;
            for(int j = 1; j < LOG; j++){
                if(~lca[j-1][t])
                    lca[j][t] = lca[j-1][lca[j-1][t]];
            }
            if(dist(t, a[id[t]]) < dist(t, b[id[t]]))
                swap(a, b);
            if(dist(t, a[id[t]]) > mx[id[t]]){
                mx[id[t]] = dist(t, a[id[t]]);
                b[id[t]] = t;
            }
        }
        else{
            scan(u);
            print(max(dist(u, a[id[u]]), dist(u, b[id[u]])));
        }
    }
    
    return 0;
}