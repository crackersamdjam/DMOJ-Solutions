#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <stdio.h>
#include <algorithm>

#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}

int N, a[100], dif;

int main(){
    
    scan(N);
    
    for(int i = 0; i < N; i++)
        scan(a[i]);
    
    std::sort(a, a+N);
    
    dif = a[1] - a[0];
    for(int i = 2; i < N; i++)
        dif = std::__gcd(dif, a[i] - a[i-1]);
    
    for(int i = 2; i*i <= dif; i++){
        if(dif%i == 0){
            print(i), pc(32);
            int j = dif/i;
            if(i != j)
                print(j), pc(32);
        }
    }
    print(dif);
    pc(10);
    
    return 0;
}