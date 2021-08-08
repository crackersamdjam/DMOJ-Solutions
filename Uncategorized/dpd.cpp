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
typedef long long ll;
const int MM = 1e5+2;

int N, W;
ll dp[MM];

int main(){
    
    scan(N, W);
    
    for(int i = 0,w,v; i < N; i++){
        scan(w, v);
        for(int j = W; j >= w; j--){
            dp[j] = max(dp[j], dp[j-w] + v);
        }
    }
    
    ll ans = 0;
    for(int i = 0; i <= W; i++)
        ans = max(ans, dp[i]);
    
    print(ans);
    
    return 0;
}