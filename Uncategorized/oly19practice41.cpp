#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef long long ll;
const int MM = 2e5+2;

int T, n, m, k, x, a[MM];
ll bit[MM];
priority_queue<ll> pq;

void up(int i, int v){
    for(; i < MM; i += i&-i)
        bit[i] += v*x;
}

ll get(int i){
    ll ret = 0;
    for(; i; i -= i&-i)
        ret += bit[i];
    return ret;
}

struct st{
    int l, r;
} q[MM];

bool test(ll mid){
    
    memset(bit, 0, sizeof(bit[0])*(n+2));
    
    while(!pq.empty())
        pq.pop();
    for(int i = 1, cnt = 0, l = 0; i <= n; i++){
        
        while(l < m && q[l].l == i){
            pq.push(q[l++].r);
        }
        
        while(a[i] + get(i) < mid){
            if(pq.empty() || cnt++ == k)
                return 0;
            
            up(i, 1);
            up(pq.top()+1, -1);
            pq.pop();
        }
    }
    return 1;
}

int main(){
    
    scan(T);
    
    while(T--){
        
        scan(n, m, k, x);
        
        for(int i = 1; i <= n; i++)
            scan(a[i]);
        
        for(int i = 0; i < m; i++)
            scan(q[i].l, q[i].r);
        
        sort(q, q+m, [](st fs, st ss){
            if(fs.l == ss.l)
                return fs.r > ss.r;
            return fs.l < ss.l;
        });
        
        ll l = 1, mid, r = 1e15;
        while(l <= r){
            mid = (l+r)/2;
            if(test(mid))
                l = mid+1;
            else
                r = mid-1;
        }
        
        print(r);
    }
    
    return 0;
}