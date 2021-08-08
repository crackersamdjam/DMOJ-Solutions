#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 2e4;

int n, t, dp[MM], s[MM], u[MM];
struct st{
    int c, v;
};
vector<st> v;

int main(){
    scan(n, t);
    for(int i = 0; i < n; i++){
        scan(s[i]);
        for(int j = 1; j < MM; j *= 2){
            v.push_back({j, s[i]*j});
        }
    }
    for(int i = 0; i < n; i++){
        scan(u[i]);
        for(int j = 1; j <= u[i]; j *= 2){
            u[i] -= j;
            v.push_back({j, -s[i]*j});
        }
        v.push_back({u[i], -s[i]*u[i]});
    }
    
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for(auto i: v){
        if(i.v > 0){
            for(int j = MM-1; j >= i.v; j--)
                dp[j] = min(dp[j], dp[j-i.v] + i.c);
        }
        else{
            for(int j = 0; j-i.v < MM; j++)
                dp[j] = min(dp[j], dp[j-i.v] + i.c);
        }
    }
    if(dp[t] > 1e9)
        print(-1);
    else
        print(dp[t]);
    
    return 0;
}