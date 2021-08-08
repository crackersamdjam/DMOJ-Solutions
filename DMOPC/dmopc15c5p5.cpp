#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(32);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

using namespace std;
const int MM = 2e5+1, mod = 1e9+7;

int N, seq[MM], root, out[MM], bit[MM];
vector<int> cl[MM];


inline void update(int i, int v){
    for(; i < MM; i += i&-i)
        bit[i] += v, bit[i] %= mod;
}

inline int query(int i){
    int ret = 0;
    for(; i; i -= i&-i)
        ret += bit[i], ret %= mod;
    return ret;
}

void dfs(int cur){
    
    int old = query(seq[cur]);
    
    for(int &u: cl[cur])
        dfs(u);
    
    int ans = query(seq[cur]) - old + 1;
    ans %= mod;
    ans += mod;
    ans %= mod;
    out[cur] = ans;
    update(seq[cur], ans);
}

int main(){
    
    scan(N);
    
    for(int i = 1,par; i <= N; i++){
        scan(par);
        cl[par].push_back(i);
        if(!par)
            root = i;
    }
    
    for(int i = 1,s; i <= N; i++){
        scan(s);
        seq[s] = i;
    }
    
    dfs(root);
    
    for(int i = 1; i <= N; i++)
        print(out[i]);
    
    return 0;
}