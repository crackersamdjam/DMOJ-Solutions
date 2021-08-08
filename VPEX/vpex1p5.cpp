#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1e4+2, MN = 101;

int n, q, c[MM], v[MM], dp[MM][MN];
long long ans;

struct st{
    int l, r, t;
};

void go(int l, int r, vector<st> &av){
    if(l > r || av.empty())
        return;
    int m = (l+r)/2;
    vector<st> lv, rv, cv;
    for(auto i: av){
        if(i.r < m)
            lv.emplace_back(i);
        else if(i.l > m)
            rv.emplace_back(i);
        else
            cv.emplace_back(i);
    }
    go(l, m, lv);
    go(m+1, r, rv);
    if(cv.empty())
        return;
    
    for(int i = 0; i < MN; i++)
        dp[m][i] = (i >= c[m])*v[m];
    for(int i = m-1; i >= l; i--){
        memcpy(dp[i], dp[i+1], sizeof dp[i+1]);
        for(int j = 100; j >= c[i]; j--)
            dp[i][j] = max(dp[i][j], v[i] + dp[i][j-c[i]]);
    }
    for(int i = 0; i < MN; i++)
        dp[m+1][i] = (i >= c[m+1])*v[m+1];
    for(int i = m+2; i <= r; i++){
        memcpy(dp[i], dp[i-1], sizeof dp[i-1]);
        for(int j = 100; j >= c[i]; j--)
            dp[i][j] = max(dp[i][j], v[i] + dp[i][j-c[i]]);
    }
    for(auto p: cv){
        int val = 0;
        for(int i = 0; i <= p.t; i++)
            val = max(val, dp[p.l][i] + (p.l != p.r)*(p.r != m)*dp[p.r][p.t-i]);
        ans += val;
        //print(p.l, p.r, p.l, val);
    }
}

int main(){
    scan(n);
    for(int i = 1; i <= n; i++)
        scan(c[i], v[i]);
    vector<st> qu;
    scan(q);
    for(int i = 0,l,r,t; i < q; i++){
        scan(l, r, t);
        qu.push_back({l, r, t});
    }
    go(1, n, qu);
    print(ans);
    
    return 0;
}