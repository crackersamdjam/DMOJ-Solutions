#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#define _CRT_SECURE_NO_WARNINGS
#endif
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
const int MM = 1e5+2, MN = 17;

int N, Q, dep[MM], lca[17][MM], f[17][MM], s[17][MM];
struct st{
    int u, w;
};
vector<st> adj[MM];

void dfs(int cur, int pre){
    for(st &e: adj[cur]){
        if(e.u != pre){
            
            dep[e.u] = dep[cur] + 1;
            lca[0][e.u] = cur;
            f[0][e.u] = e.w, s[0][e.u] = -1;
            
            dfs(e.u, cur);
        }
    }
}

int arr[4];
inline void build(){
    for(int i = 1; i < MN; i++){
        for(int j = 1; j <= N; j++){
            
            if(lca[i-1][j] != -1){
                lca[i][j] = lca[i-1][lca[i-1][j]];
                
                arr[0] = f[i-1][j], arr[1] = s[i-1][j];
                arr[2] = f[i-1][lca[i-1][j]], arr[3] = s[i-1][lca[i-1][j]];
                sort(arr, arr+4);
                f[i][j] = arr[3];
                s[i][j] = arr[2];
            }
        }
    }
}
inline int getLca(int a, int b){
    if(dep[a] < dep[b])
        swap(a, b);
    for(int i = MN-1; i >= 0; i--){
        if((lca[i][a] != -1) && (dep[lca[i][a]] >= dep[b]))
            a = lca[i][a];
    }
    if(a == b)
        return a;
    for(int i = MN-1; i >= 0; i--){
        if((lca[i][a] != -1) && (lca[i][b] != -1) && (lca[i][a] != lca[i][b])){
            a = lca[i][a];
            b = lca[i][b];
        }
    }
    return lca[0][a];
}

inline int query(int a, int b){
    
    int rt = getLca(a, b);
    int fst = -1, sec = -1;
    for(int i = MN-1; i >= 0; i--){
        if(dep[a] >= dep[rt] + (1<<i)){
            if(f[i][a] > fst){
                sec = fst;
                fst = f[i][a];
            }else if(f[i][a] > sec)
                sec = f[i][a];
            if(s[i][a] > sec)
                sec = s[i][a];
            
            a = lca[i][a];
        }
    }
    
    for(int i = MN-1; i >= 0; i--){
        if(dep[b] >= dep[rt] + (1<<i)){
            if(f[i][b] > fst){
                sec = fst;
                fst = f[i][b];
            }else if(f[i][b] > sec)
                sec = f[i][b];
            if(s[i][b] > sec)
                sec = s[i][b];
            
            b = lca[i][b];
        }
    }
    return sec;
}

int main(){
    
    memset(lca, -1, sizeof(lca));
    //memset(f, -1, sizeof(f));
    
    scan(N);
    for(int i = 0,a,b,c; i < N-1; i++){
        scan(a, b, c);
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    
    dfs(1, 0);
    build();
    scan(Q);
    
    for(int i = 0,a,b; i < Q; i++){
        scan(a, b);
        print(query(a,b));
    }
    return 0;
}