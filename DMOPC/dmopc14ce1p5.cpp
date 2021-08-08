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

int N, K = 1000;


struct st{
    int val, time;
    friend bool operator<(const st &x, const st &y){
        if(x.val == y.val)
            return x.time > y.time;
        return x.val < y.val;
    }
    friend st operator+(const st &x, int &y){
        return {(x.val + y), x.time+1};
    }
} dp[51][1001];

int main(){
    
    scan(N);
    for(int i = 1,h,e,p; i <= N; i++){
        scan(h, e, p);
        
        for(int j = 0; j <= K; j++){
            dp[i][j] = dp[i-1][j];
        }
        
        while(h > 0){
            for(int j = K; j >= p; j--){
                dp[i][j] = max(dp[i][j], dp[i][j-p] + h);
            }
            h -= e;
        }
    }
    
    scan(K);
    
    st ans = {0, 0};
    for(int i = 0; i <= K; i++)
        ans = max(ans, dp[N][i]);
    
    print(ans.val);
    print(ans.time);
    
    return 0;
}