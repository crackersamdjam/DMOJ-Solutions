#include <bits/stdc++.h>
#define bound(x) (x+300)
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;

int N, D, a[301], lc[301], rc[301], dp[301][601];

void go(int n){
    
    if(rc[n]){
        go(rc[n]);
        go(lc[n]);
        
        for(int i = 0; i <= 600; i++){
            for(int j = 0; j <= 600; j++){
                int x = i+j-300+a[n];
                if(x >= 0 && x <= 600){
                    dp[n][x] = min(dp[n][x], dp[lc[n]][i] + dp[rc[n]][j]);
                }
            }
        }
        //cut both
        dp[n][a[n] + 300] = min(dp[n][a[n] + 300], 2);
        //one left, right
        for(int i = 0; i <= 600; i++){
            int x = i+a[n];
            if(x >= 0 && x <= 600){
                dp[n][x] = min(dp[n][x], dp[lc[n]][i] + 1);
                dp[n][x] = min(dp[n][x], dp[rc[n]][i] + 1);
            }
        }
    }
    else if(lc[n]){
        go(lc[n]);
        
        for(int i = 0; i <= 600; i++){
            int x = i+a[n];
            if(x >= 0 && x <= 600)
                dp[n][x] = dp[lc[n]][i];
        }
        //cut left
        dp[n][a[n] + 300] = min(dp[n][a[n] + 300], 1);
    }
    else
        dp[n][a[n] + 300] = 0;
}

int main(){
    
    memset(dp, 0x3f, sizeof dp);
    
    scan(N, D);
    
    for(int i = 0,id,v,c; i < N; i++){
        scan(id, v, c);
        a[id] = v?1:-1;
        
        if(c >= 1)
            scan(lc[id]);
        if(c == 2)
            scan(rc[id]);
    }
    
    go(0);
    
    int ans = dp[0][300+D];
    print(ans == 0x3f3f3f3f? -1: ans);
    
    return 0;
}