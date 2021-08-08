#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4,popcnt,abm,mmx,tune=native")

#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

void init(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
    #endif
}
using std::min, std::max;
using ll = long long;
const int MM = 1e6+1;
int n, a[MM];
std::pair<ll, std::pair<int, int>> r, c;
std::vector<std::pair<ll, int>> v = {{-1e10, -1}, {1e10, -1}, {-1e11, -1}, {1e11, -1}, {-1e10, -1}, {1e10, -1}, {-1e11, -1}, {1e11, -1}};
std::unordered_map<int, int> cnt;

int main(){
    r.first = 1e12;
    init();
    scan(n);
    for(int i = 1; i <= n; i++){
        scan(a[i]);
        if(++cnt[a[i]] < 2)
        v.emplace_back(a[i], i);
    }
    sort(v.begin(), v.end());

    for(int i = 1; i <= n; i++){
        auto p = upper_bound(v.begin(), v.end(), std::make_pair((ll)-a[i], i));
        if(p->second == i) p++;
        c = {abs(p->first+a[i]), {std::min(i, p->second), std::max(i, p->second)}};
        r = min(r, c);

        p--; if(p->second == i) p--;
        c = {abs(p->first+a[i]), {std::min(i, p->second), std::max(i, p->second)}};
        r = min(r, c);
    }

    print(r.first);
    print(r.second.first, r.second.second);
    
    return 0;
}