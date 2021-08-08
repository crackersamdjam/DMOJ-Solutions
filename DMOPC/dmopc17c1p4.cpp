#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef long long ll;
const int M = 5002;

int n, h;
ll dp[2][M];

int main(){
    
    scan(n, h);
    
    for(int t = 0,a,b,c,d; t < n; t++){
        int i = t&1, p = i^1;
        scan(a, b, c, d);
        
        for(int j = b; j <= h; j++)
            dp[i][j] = dp[p][j-b] + a;
        
        for(int j = b+d; j <= h; j++)
            dp[i][j] = max(dp[i][j], dp[i][j-d] + c);
        
        for(int j = 0; j <= h; j++)
            dp[i][j] = max(dp[i][j], dp[p][j]);
    }
    
    print(*max_element(dp[n&1^1], dp[n&1^1]+h+1));
    
    return 0;
}