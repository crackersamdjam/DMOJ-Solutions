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
using ll = __int128;
const int MM = 1e5+5;

int n;
ll a[MM], ans, ans2, best;
vector<ll> v[2];
ll sq(ll x){
    return x*x;
}

int main(){
    scan(n);
    for(int i = 0; i < n; i++)
        scan(a[i]);

    if(n == 2){
        return print(2*sq(a[0] - a[1])), 0;
    }

    sort(a, a+n);
    for(int i = 1; i < n; i++){
        v[i&1].push_back(a[i]);
    }

    ll last = a[0];
    for(ll i: v[1]){
        ans += sq(last-i);
        last = i;
    }
    reverse(all(v[0]));
    for(int i: v[0]){
        ans += sq(last-i);
        last = i;
    }
    ans += sq(last-a[0]);

    last = a[0];
    reverse(all(v[0]));
    reverse(all(v[1]));
    for(ll i: v[0]){
        ans2 += sq(last-i);
        last = i;
    }
    for(int i: v[1]){
        ans2 += sq(last-i);
        last = i;
    }
    ans2 += sq(last-a[0]);

    best = min(ans, ans2);

    ans = ans2 = 0;
    reverse(a, a+n);

    v[0].clear();
    v[1].clear();
    for(int i = 1; i < n; i++){
        v[i&1].push_back(a[i]);
    }
    last = a[0];
    for(ll i: v[1]){
        ans += sq(last-i);
        last = i;
    }
    reverse(all(v[0]));
    for(int i: v[0]){
        ans += sq(last-i);
        last = i;
    }
    ans += sq(last-a[0]);

    last = a[0];
    reverse(all(v[0]));
    reverse(all(v[1]));
    for(ll i: v[0]){
        ans2 += sq(last-i);
        last = i;
    }
    for(int i: v[1]){
        ans2 += sq(last-i);
        last = i;
    }
    ans2 += sq(last-a[0]);

    best = min({best, ans, ans2});
    print(best);

    
    return 0;
}