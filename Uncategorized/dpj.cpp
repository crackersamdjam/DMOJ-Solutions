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
const int MM = 302;
 
int n;
double dp[MM][MM][MM];
 
double go(int i, int j, int k){
    if(dp[i][j][k] != -1)
        return dp[i][j][k];
    
    double ret = 1;
    int sum = i+j+k;
    
    if(i)
        ret += (1.0*i/n)*go(i-1, j, k);
    if(j)
        ret += (1.0*j/n)*go(i+1, j-1, k);
    if(k)
        ret += (1.0*k/n)*go(i, j+1, k-1);
    
    return dp[i][j][k] = ret/(1-(1.0*n-sum)/n);
}
 
int main(){
    for(int i = 0; i < MM; i++)
        for(int j = 0; j < MM; j++)
            for(int k = 0; k < MM; k++)
                dp[i][j][k] = -1;
    
    dp[0][0][0] = 0;
    scan(n);
    int a[4] = {0,0,0,0};
    for(int i = 0,s; i < n; i++){
        scan(s);
        a[s]++;
    }
    printf("%.10lf\n", go(a[1], a[2], a[3]));
    return 0;
}