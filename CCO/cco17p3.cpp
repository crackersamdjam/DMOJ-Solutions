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
const int MM = 6e5+2;

ll bit[MM], ans[MM];

void up(int i, ll v){
    for(; i < MM; i += i&-i)
        bit[i] += v;
}

ll qu(int i){
    ll r = 0;
    for(; i; i -= i&-i)
        r += bit[i];
    return r;
}

struct st{
    //1 add, 2 query, 3 remove
    ll op, x, l, r, v;
    bool operator <(const st &o) const{
        if(x != o.x)
            return x < o.x;
        return op < o.op;
    }
};

vector<st> q;
map<ll, int> mp;
int n, m;

ll conv(ll i){
    ll r = 0;
    for(int j = 0; j < 60; j++){
        if(i&(1LL<<j))
            r |= (1LL<<(60-j));
    }
    return r;
}

int main(){
    
    scan(n, m);
    
    for(ll i = 0,x,y,v; i < n; i++){
        scan(x, y, v);
        x = conv(x), y = conv(y);
        ll lx = x&-x, ly = y&-y; //last bit
        
        mp[y-ly+1] = mp[y+ly-1] = 0;
        q.push_back({1, x-lx+1, y-ly+1, y+ly-1, v});
        q.push_back({3, x+lx-1, y-ly+1, y+ly-1, v});
    }
    
    for(ll i = 0,x,y; i < m; i++){
        scan(x, y);
        x = conv(x), y = conv(y);
        mp[y] = 0;
        q.push_back({2, x, y, i});
    }
    
    int t = 0;
    for(auto &x: mp)
        x.second = ++t;
    
    sort(q.begin(), q.end());
    
    for(auto i: q){
        if(i.op == 1){
            up(mp[i.l], i.v);
            up(mp[i.r]+1, -i.v);
        }
        else if(i.op == 2){
            ans[i.r] = qu(mp[i.l]);
        }
        else{
            up(mp[i.l], -i.v);
            up(mp[i.r]+1, i.v);
        }
    }
    
    for(int i = 0; i < m; i++)
        print(ans[i]);
    
    
    return 0;
}
/*
 * reverse bits, ignore until last '1'
 * for both x and y
 * then update rectangle and line-sweep, query points (tinted glass window)
 *
 * e.g.
 *
 * 3
 * 0011 0101 0111 1001 1011 1101 1111
 * reverse
 * 1100 ... 1111
 * update [1100, 1111] += v
 *
 * do for y as well, so line sweep
 *
 * cord-comp one side and line sweep other
 *
 */