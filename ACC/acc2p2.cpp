#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
const int MM = 501;

int N, st;
vector<int> adj[MM];
bool vis[MM][MM];

void dfs(int cur){
    for(int u: adj[cur]){
        if(vis[st][u])
            continue;
        vis[st][u] = 1;
        dfs(u);
    }
}

int main(){
    
    scan(N);
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(gc == '1')
                adj[i].push_back(j);
        }
        gc;
    }
    
    for(int i = 1; i <= N; i++){
        st = i;
        vis[st][i] = 1;
        dfs(i);
    }
    
    int cnt = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j < i; j++)
            if(!vis[i][j] && !vis[j][i])
                cnt++;
    }
    
    print(cnt);
    
    return 0;
}
/*
 * there must be exactly one path between two nodes
 * 1 --> 2, 3
 * 3 --> 4
 * only need one, 2 --> 3
 *
 * but if 3 --> 2, then 2, 4 unsure
 *
 * is the problem asking for unsure pairs, or minimum edges too add
 */