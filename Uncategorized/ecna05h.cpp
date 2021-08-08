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
const int MM = 1002;

int N, dp[MM][MM], a[MM];
bool vis[MM][MM];

int go(int l, int r){
    if(l == r)
        return a[l];
    if(vis[l][r])
        return dp[l][r];
    vis[l][r] = 1;
    
    if((r-l+1)&1){
        if(a[l] >= a[r])
            return dp[l][r] = a[l] - go(l+1, r);
        else
            return dp[l][r] = a[r] - go(l, r-1);
    }
    else{
        return dp[l][r] = max(a[l] - go(l+1, r), a[r] - go(l, r-1));
    }
}

int cnt = 0;
int main(){
    while(++cnt){
        scan(N);
        if(N == 0)
            break;
        
        memset(vis, 0, sizeof(vis));
        
        for(int i = 1; i <= N; i++)
            scan(a[i]);
        
        printf("In game %d, the greedy strategy might lose by as many as %d points.\n", cnt, go(1, N));
    }
    return 0;
}