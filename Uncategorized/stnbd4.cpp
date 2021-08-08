#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

#define block(nx) ((nx)/sz)

using namespace std;
typedef long long ll;
const int MM = 1e5+1;

int N, Q, a[MM], sz;
ll out[MM], bit[MM], in[MM];
map<ll, int> mp;

struct qry{
    int l, r, id;
} q[MM];

inline void update(int i, int v){
    for(; i < MM; i += i&-i)
        bit[i] += v;
}

inline int query(int i){
    int ret = 0;
    for(; i > 0; i -= i&-i)
        ret += bit[i];
    return ret;
}

int main(){
    
    scan(N);
    
    sz = 360;
    
    for(int i = 1; i <= N; i++){
        scan(in[i]);
        mp[in[i]] = 0;
    }
    
    int t = 0;
    for(auto &itr: mp)
        itr.second = ++t;
    
    for(int i = 1; i <= N; i++)
        a[i] = mp[in[i]];
    
    scan(Q);
    
    for(int i = 0; i < Q; i++){
        scan(q[i].l, q[i].r);
        q[i].id = i;
    }
    
    sort(q, q+Q, [](const qry &x, const qry &y){
        
        int t1 = block(x.l), t2 = block(y.l);
        
        if(t1 == t2)
            return x.r < y.r;
        return t1 < t2;
    });
    
    
    int l = 1, r = 1;
    ll ans = 0;
    update(a[1], 1);
    
    for(int i = 0; i < Q; i++){
        
        while(l > q[i].l){
            l--;
            ans += query(a[l]-1);
            update(a[l], 1);
        }
        
        while(r > q[i].r){
            int v = r-l - (query(a[r])-1);
            ans -= v;
            update(a[r], -1);
            r--;
        }
        
        while(r < q[i].r){
            r++;
            int v = r-l - query(a[r]);
            ans += v;
            update(a[r], 1);
        }
        
        while(l < q[i].l){
            ans -= query(a[l]-1);
            update(a[l], -1);
            l++;
        }
        
        out[q[i].id] = ans;
    }
    
    
    for(int i = 0; i < Q; i++)
        print(out[i]);
    
    
    return 0;
}