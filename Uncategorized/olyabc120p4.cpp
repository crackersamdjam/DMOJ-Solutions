#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef long long ll;
const int MM = 1e5+1;

int N, M, par[MM], sz[MM], a[MM], b[MM];
ll ans[MM], cnt;

int find(int x){
    while(x != par[x]){
        x = par[x];
        par[x] = par[par[x]];
    }
    return x;
}

int main(){
    
    scan(N, M);
    
    for(int i = 1; i <= N; i++){
        par[i] = i, sz[i] = 1;
    }
    
    cnt = (ll)N*(N-1)/2;
    
    for(int i = 0; i < M; i++){
        scan(a[i], b[i]);
    }
    
    ans[M] = cnt;
    for(int i = M-1; i >= 0; i--){
        ans[i] = cnt;
        int fa = find(a[i]), fb = find(b[i]);
        //print(fa, fb);
        if(fa != fb){
            par[fb] = fa;
            cnt -= (ll)sz[fa]*sz[fb];
            //printf("sub %d\n", sz[fa] * sz[fb]);
            sz[fa] += sz[fb];
        }
    }
    
    for(int i = 0; i < M; i++){
        print(ans[i]);
    }
    
    return 0;
}