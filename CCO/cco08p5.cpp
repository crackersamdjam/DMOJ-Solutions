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
const int MM = 1e7+2;

int N, sum, cnt[MM/2];
bool dp[MM/2];

int main(){
    
    scan(N);
    dp[0] = 1;
    for(int i = 0,k,c; i < N; i++){
        scan(k, c);
        sum += k*c;
        memset(cnt, 0, sizeof(cnt));
        for(int j = 0; j < MM/2; j++){
            if(dp[j] && cnt[j] < k){
                if(!dp[j+c]){
                    dp[j+c] = 1;
                    cnt[j+c] = cnt[j] + 1;
                }
            }
        }
    }
    int ans = sum/2;
    for(; !dp[ans]; ans--);
    
    print(sum - 2*ans);
    
    return 0;
}