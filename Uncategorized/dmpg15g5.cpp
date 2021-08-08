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
typedef long long ll;
const int MM = 2002;

int N, R;
ll dp[MM];
priority_queue<int, vector<int>, less<int>> items[MM];

int main(){
    
    scan(N, R);
    
    for(int i = 0,E,C,V,CA,CB,CM,VA,VB,VM; i < N; i++){
        
        scan(E, C, V, CA, CB, CM, VA, VB, VM);
        int cost = C, val = V;
        
        for(int j = 1; j <= E; j++){
            if(cost <= R)
                items[cost].push(val);
            
            cost = ((ll)cost * CA + CB) % CM;
            val = ((ll)val * VA + VB) % VM;
        }
    }
    
    for(int i = 1; i <= R; i++){
        for(int j = 0; j < R/i && !items[i].empty(); j++){
            
            int val = items[i].top();
            items[i].pop();
            for(int k = R; k >= i; k--){
                dp[k] = max(dp[k], dp[k-i] + val);
            }
        }
    }
    
    ll ans = 0;
    
    for(int i = 0; i <= R; i++)
        ans = max(ans, dp[i]);
    
    while(!items[0].empty()){
        ans += items[0].top();
        items[0].pop();
    }
    
    print(ans);
    return 0;
}