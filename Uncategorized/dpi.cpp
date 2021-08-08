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
const int MM = 3002;
 
int N;
double dp[MM][2];
//number of heads, previous and cur
 
int main(){
    
    scanf("%d", &N);
    dp[0][1] = 1;
    double p;
    
    for(int ii = 0,i; ii < N; ii++){
        i = ii&1;
        scanf("%lf", &p);
        dp[0][i] = dp[0][i^1]*(1-p);
        for(int j = 1; j <= N; j++){
            dp[j][i] = dp[j-1][i^1]*p + dp[j][i^1]*(1-p);
        }
    }
    double sum = 0;
    for(int i = (N+1)/2; i <= N; i++){
        sum += dp[i][N&1^1];
    }
    printf("%.10lf\n", sum);
    
    return 0;
}