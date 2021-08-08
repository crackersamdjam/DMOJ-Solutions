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

int T;
bool dp[51];

int main(){
    
    scan(T);
    
    for(int i = 0,a,b,c; i < T; i++){
        scan(a, b, c);
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        for(int j = a; j < 51; j++){
            dp[j] |= dp[j-a];
        }
        for(int j = b; j < 51; j++){
            dp[j] |= dp[j-b];
        }
        puts(dp[c]? "YES" : "NO");
    }
    
    return 0;
}