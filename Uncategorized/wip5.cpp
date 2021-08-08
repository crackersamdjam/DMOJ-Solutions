#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

using namespace std;
typedef long long ll;
const int MM = 1e5+1;

int N, Q, in[MM];

ll sum[MM], indextree[MM];

inline void update(ll (&tree)[MM], int i, ll val){
    for(; i < MM; i += i&-i)
        tree[i] += val;
}

inline ll query(ll (&tree)[MM], int i){
    ll ret = 0;
    for(; i; i -= i&-i)
        ret += tree[i];
    return ret;
}

inline int find(ll ind){
    int l = 1, m, r = N;
    while(l <= r){
        m = (l+r)/2;
        if(query(indextree, m) > ind)
            r = m-1;
        else
            l = m+1;
    }
    return r;
}

int main(){
    
    scan(N, Q);
    
    for(int i = 1; i <= N; i++){
        scan(in[i]);
        update(sum, i, in[i]);
        update(indextree, i, 1);
    }
    
    for(int i = 0; i < Q; i++){
        ll op, a, b;
        scan(op, a, b);
        if(op == 1){
            int old = find(a);
            update(sum, old+1, in[old]*b);
            update(indextree, old+1, b);
        }
        else{
            a--;
            int fa = find(a), fb = find(b);
            print(query(sum, fb) + in[fb]*(b - query(indextree, fb))
                - (query(sum, fa) + in[fa]*(a - query(indextree, fa))));
        }
    }
    
    return 0;
}