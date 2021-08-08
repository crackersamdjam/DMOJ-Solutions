// :cheese:
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

typedef long long ll;

#define max(x, y) ((x) > (y) ? (x) : (y))

int n;
ll dp[1<<16], v[16][16];

int main(){
    
    scan(n);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            scan(v[i][j]);
    }
    
    for(int i = 0; i < (1<<n); i++){
        for(int j = 0; j < n; j++){
            for(int k = j+1; k < n; k++){
                if((i>>j)&(i>>k)&1)
                    dp[i] += v[j][k];
            }
        }
    }
    
    std::vector<int> ind(16);
    for(int i = 0; i < (1<<n); i++){
        ind.clear();
        for(int j = 0; j < n; j++)
            if((i>>j)&1)
                ind.push_back(j);
        
        for(int j = 0; j < (1<<ind.size()); j++){
            int nx = 0;
            for(int k = 0; k < n; k++)
                if((j>>k)&1)
                    nx |= (1<<ind[k]);
            dp[i] = max(dp[i], dp[nx] + dp[i^nx]);
        }
    }
    
    print(dp[(1<<n)-1]);
    
    return 0;
}
/*
 * 16C0*2^0 + 16C1*2^1 + 16C2*2^2 + 16C3*2^3 ... 16C15*2^15
 * < 1e7 at max
 * total < 1.6e8
 */