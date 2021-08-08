#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <iostream>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
#define min(x, y) x < y ? x : y
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

const int MM = 1001;

int N, M, a[MM][MM], p[MM][MM];
long long ans;

int main(){
    
    scan(N, M);
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            scan(a[i][j]);
            p[i][j] = (a[i][j] == a[i-1][j]) ? p[i-1][j] + 1 : 1;
        }
    }
    
    for(int i = 1,h; i <= N; i++){
        for(int j = 1; j <= M; j++){
            h = p[i][j];
            for(int k = j; k; k--){
                if(a[i][j] ^ a[i][k])
                    break;
                h = min(h, p[i][k]);
                ans += h;
            }
        }
    }
    
    print(ans);
    
    return 0;
}