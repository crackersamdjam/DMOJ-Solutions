#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef pair<int, int> pii;
const int MM = 1e6+5;

#define lc (l<<1)
#define rc (l<<1|1)
#define bound(x) max(0, min(N-1, x))

int N, K, Q, v[MM], pre, out[MM];

struct node{
    int best;
    pii rmq;
} a[MM<<1];

pii rmq(int l, int r){
    pii ret = {-1, -1};
    for(l += N, r += N+1; l < r; l >>= 1, r >>= 1){
        if(l&1)
            ret = max(ret, a[l++].rmq);
        if(r&1)
            ret = max(ret, a[--r].rmq);
    }
    return ret;
}

void update(int l, int n){
    a[l+N].rmq.first = v[l];
    l += N;
    a[l].best = n;
    for(l >>= 1; l > 0; l >>= 1){
        a[l].rmq = max(a[lc].rmq, a[rc].rmq);
        a[l].best = max(a[lc].best, a[rc].best);
    }
}

int main(){
    
    scan(N, K, Q);
    
    for(int i = 0; i < N; i++){
        scan(v[i]);
        a[i+N].rmq = {v[i], i};
    }
    
    for(int l = N-1; l > 0; l--)
        a[l].rmq = max(a[lc].rmq, a[rc].rmq);
    
    for(int i = 0; i < N; i++){
        pii t = max(rmq(bound(i-K+1), i-1), rmq(i+1, bound(i+K-1)));
        if(v[i] > t.first || (v[i] == t.first && i > t.second))
            update(i, v[i]+t.first);
    }
    
    print(pre = a[1].best);
    
    for(int i = 0,l,n; i < Q; i++){
        scan(l, n);
        l ^= pre, n ^= pre;
        v[--l] = n;
        pii f = rmq(bound(l-K+1), l-1), s = rmq(l+1, bound(l+K-1));
        int li = f.second, ri = s.second;
        
        if(v[l] >= f.first && v[l] > s.first){
            update(l, v[l] + max(f.first, s.first));
            goto gt;
        }
        update(l, 0);
        if(li >= 0 && li < N){
            pii tl = rmq(bound(li-K+1), li-1), tr = rmq(li+1, bound(li+K-1));
            if(v[li] >= tl.first && v[li] > tr.first)
                update(li, v[li] + max(tl.first, tr.first));
        }
        if(ri >= 0 && ri < N){
            pii tl = rmq(bound(ri-K+1), ri-1), tr = rmq(ri+1, bound(ri+K-1));
            if(v[ri] >= tl.first && v[ri] > tr.first)
                update(ri, v[ri] + max(tl.first, tr.first));
        }
        gt:;
        out[i] = (pre = a[1].best);
    }
    
    for(int i = 0; i < Q; i++)
        print(out[i]);
    
    return 0;
}