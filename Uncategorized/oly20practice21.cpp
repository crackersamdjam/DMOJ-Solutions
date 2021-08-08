#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;

void init(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
    #endif
}
const int MM = 205;

int n, ans;
ll a[MM], m, b[MM];
ll dp[MM][MM][MM][2];

struct st{
    int l, r, c, s;
    st(int _l, int _r, int _c, int _s){
        l = _l, r = _r, c = _c, s = _s;
    }
};
queue<st> q;

int main(){
    init();
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        // scan(a[i]);
        cin>>a[i];
        assert(a[i] > a[i-1]);
        assert(a[i] < m);
    }
    for(int i = 1; i <= n; i++){
        // scan(b[i]);
        cin>>b[i];
        assert(b[i] <= 1e9);
    }
    a[0] = 0;
    a[n+1] = m;
    b[0] = b[n+1] = -1;
    memset(dp, 0x3f, sizeof dp);
    dp[0][n+1][0][0] = 0;
    dp[0][n+1][0][1] = 0;
    q.push({0, n+1, 0, 0});
    q.push({0, n+1, 0, 1});
    while(q.size()){
        auto rm = q.front(); q.pop();
        int l = rm.l, r = rm.r, c = rm.c, s = rm.s;
        ll t = dp[l][r][c][s];
        // print(l, r, c, s, t);
        ans = max(ans, c);
        if(l+1 == r or t > 1e9)
            continue;

        ll nt = (t+a[l+1]-a[l]);
        if(s) nt += m-a[r]+a[l];
        bool v = (nt <= b[l+1]);

        if(nt < dp[l+1][r][c+v][0]){
            dp[l+1][r][c+v][0] = nt;
            q.push({l+1, r, c+v, 0});
        }

        nt = (t+a[r]-a[r-1]);
        if(!s) nt += a[l]+m-a[r];
        v = (nt <= b[r-1]);

        if(nt < dp[l][r-1][c+v][1]){
            dp[l][r-1][c+v][1] = nt;
            q.push({l, r-1, c+v, 1});
        }
    }
    assert(ans <= n);
    // print(ans);
    cout<<ans;
    
    return 0;
}