#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
const int MM = 5e5+5;

int n;
vector<pair<ll, ll>> v;
map<ll, ll> mp;
ll pre[MM], ans, psa;

int main(){
    scan(n);
    for(int i = 1; i <= n; i++){
        ll a, b;
        scan(a, b);
        mp[a] += b;
    }
    v.emplace_back(0, 0);
    for(auto i: mp)
        v.emplace_back(i);
    for(int i = 1; i < v.size(); i++){
        pre[i] = max(pre[i-1], v[i].first) + v[i].second;
        //print(i, pre[i], v[i].first, v[i].second);
        ans = max(ans, pre[i] - v[i].first);
    }
    print(ans);
    
    return 0;
}