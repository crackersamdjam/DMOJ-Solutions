#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MN = 10001;

int n, q, inf = 0x3f3f3f3f;
vector<pair<int, int>> dp[MN];

int main(){
    
    scan(n, q);
    
    dp[0].push_back({0, 0});
    for(int i = 1; i < MN; i++)
        dp[i].emplace_back(0, inf);
    for(int i = 1,v; i <= n; i++){
        scan(v);
        for(int j = v; j < MN; j++){
            int m = dp[j-v].back().second + 1;
            if(m < dp[j].back().second)
                dp[j].emplace_back(i, m);
        }
    }

    for(int i = 0, p = 0,c,l,ans; i < q; i++){
        scan(c, l);
        c ^= p, l ^= p;
        ans = (--upper_bound(dp[c].begin(), dp[c].end(), make_pair(l, inf)))->second;
        if(ans == inf)
            print(-1), p = 0;
        else
            print(p = ans);
    }
    
    return 0;
}