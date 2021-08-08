#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define f first
#define s second
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
typedef pair<ll, int> pii;
const int MM = 1e5+2;

int N, K;
ll dp[MM][2], psa[MM];
deque<pii> q;

int main(){
    
    q.push_front({0, 0});
    
    scan(N, K);
    for(int i = 1,n; i <= N; i++){
        scan(n);
        psa[i] = psa[i-1] + n;
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        
        while(!q.empty() && q.front().s < i-K)
            q.pop_front();
        
        dp[i][1] = psa[i] + q.front().f;
        
        ll cur = dp[i][0] - psa[i];
        while(!q.empty() && q.back().f <= cur)
            q.pop_back();
        
        q.push_back({cur, i});
    }
    
    print(max(dp[N][0], dp[N][1]));
    
    return 0;
}