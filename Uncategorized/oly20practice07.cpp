#include <bits/stdc++.h>
using namespace std;
using ll = __int128;

#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

int q;
ll n, m, k, mod;
struct st{
    ll sum, cnt;
    st(ll _sum = 0, ll _cnt = 0): sum(_sum), cnt(_cnt) {}
    st& operator+=(const st &o){
        sum += o.sum, cnt += o.cnt;
        sum %= mod;
        cnt %= mod;
        return *this;
    }
    st& operator*(ll x){
        sum = (sum + cnt*x) % mod;
        return *this;
    }
} dp[63][2][2][2];

st go(int i, bool a, bool b, bool c){
    if(i == -1) return {0, 1};
    st &ret = dp[i][a][b][c];
    if(~ret.sum) return ret;
    ret = {0, 0};
    ll bit = 1LL<<i;
    bool ta = (n >= bit and (!a || (n&bit))), tb = (m >= bit and (!b || (m&bit))), tc = (c && (k&bit));
    //can take a, can take b, must take c
    bool aa = !(!a || (n&bit)), bb = !(!b || (m&bit));
    
    if(tc){
        //must take 1
        if(ta) ret += go(i-1, a, bb, 1)*bit;
        if(tb) ret += go(i-1, aa, b, 1)*bit;
    }
    else{
        //take 0, 1, or 2
        ret += go(i-1, aa, bb, c);
        if(ta) ret += go(i-1, a, bb, 0)*bit;
        if(tb) ret += go(i-1, aa, b, 0)*bit;
        if(ta&&tb) ret += go(i-1, a, b, c);
    }
    
    return ret;
}

int main(){
    //freopen("in.txt", "r", stdin);
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//    cin>>q;
    scan(q);
    while(q--){
//        cin>>n>>m>>k>>mod;
        scan(n, m, k, mod);
        n--, m--;
        memset(dp, -1, sizeof dp);
        st res = go(62, 1, 1, 1);
        //cout<<res.sum<<' '<<res.cnt<<'\n';
        ll ans = res.sum-res.cnt*k;
//        cout<<(ans%mod+mod)%mod<<'\n';
        print((ans%mod+mod)%mod);
    }
    
    return 0;
}