#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 4e5+1;

int N, M, K, n[MM], cnt, par[MM], ans[MM];
unordered_map<int, int> mp;
struct edge{
    int a, b;
    bool operator<(const edge &x) const{
        int v = max(mp[x.a], mp[x.b]), w = max(mp[a], mp[b]);
        return v > w;
    }
} a[MM];

inline int find(int x){
    while(x != par[x]){
        x = par[x];
        par[x] = par[par[x]];
    }
    return x;
}

int main(){
    
    scan(N, M);
    
    for(int i = 0; i < N; i++)
        par[i] = i;
    
    for(int i = 0; i < M; i++){
        scan(a[i].a, a[i].b);
    }
    
    scan(K);
    
    for(int i = 0,k; i < K; i++){
        scan(k);
        mp[k] = K-i;
        n[i] = k;
    }
    
    sort(a, a+M);
    
    cnt = N-K;
    
    int l = 0;
    while(max(mp[a[l].a], mp[a[l].b]) == 0 && l < M){
        int fa = find(a[l].a), fb = find(a[l].b);
        if(fa ^ fb){
            par[fa] = fb;
            cnt--;
        }
        l++;
    }
    
    ans[K] = cnt;
    
    for(int i = K-1; i >= 0; i--){
        cnt++;
        while(l < M && (max(mp[a[l].a], mp[a[l].b]) == K-i)){
            int fa = find(a[l].a), fb = find(a[l].b);
            if(fa ^ fb){
                par[fa] = fb;
                cnt--;
            }
            l++;
        }
        ans[i] = cnt;
    }
    
    for(int i = 0; i <= K; i++)
        print(ans[i]);
    
    return 0;
}