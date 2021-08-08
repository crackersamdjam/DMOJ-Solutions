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
const int MM = 51;

int N, M, dp[MM][MM][MM][MM], a[MM][MM];

inline int area(int lx, int rx, int ly, int ry){
    return a[rx][ry] - a[lx-1][ry] - a[rx][ly-1] + a[lx-1][ly-1];
}

int go(int lx, int rx, int ly, int ry){
    
    if(lx == rx && ly == ry)
        return 0;
    if(dp[lx][rx][ly][ry])
        return dp[lx][rx][ly][ry];
    
    int ret = INT_MAX;
    //try horizontal and vertical
    for(int i = lx; i < rx; i++){
        ret = min(ret, go(lx, i, ly, ry) + go(i+1, rx, ly, ry));
    }
    for(int i = ly; i < ry; i++){
        ret = min(ret, go(lx, rx, ly, i) + go(lx, rx, i+1, ry));
    }
    
    ret += area(lx, rx, ly, ry);
    return dp[lx][rx][ly][ry] = ret;
}

int main(){
    
    scan(N, M);
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            scan(a[i][j]);
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
            //printf("%d ", a[i][j]);
        }
        //puts("");
    }
    print(go(1, N, 1, M));
    
    return 0;
}