#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
const int MM = 3e5+1;

int N, a[MM], dp[60][MM], ans;

int main(){
    
    scan(N);
    
    for(int i = 1; i <= N; i++){
        scan(a[i]);
        dp[a[i]][i] = i+1; //right exclusive
    }
    
    for(int j = 2; j < 60; j++){
        for(int i = 1; i <= N; i++){
            int endpt = dp[j-1][i];
            if(dp[j-1][endpt]){
                dp[j][i] = dp[j-1][endpt];
                ans = max(ans, j);
            }
        }
    }
    
    print(ans);
    
    return 0;
}
/*
 * max number is logn + 40, 58
 * dp[val][i]
 * starting from i, get val
 * stores endpoint
 *
 * like lca binary lifting
 * to check if dp[val][i],
 *      endpt = dp[val-1][i]  first endpoint
 *      if dp[val-1][endpt]
 *          yes
 *
 */