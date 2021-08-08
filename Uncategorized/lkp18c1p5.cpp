#include <bits/stdc++.h>
#define lc (rt<<1)
#define rc (rt<<1|1)
#define nl (tree[rt].l)
#define nr (tree[rt].r)
#define m  ((nl+nr)>>1)
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(32);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

using namespace std;
const int MM = 1e5+1;

int N, M, K, a[MM], order[21], cnt[21];

struct node{
    int l, r, lp, cnt[21];
} tree[MM*3];

void push_up(int rt){
    for(int i = 1; i <= K; i++)
        tree[rt].cnt[i] = tree[lc].cnt[i] + tree[rc].cnt[i];
}

void push_down(int rt){
    int &v = tree[rt].lp;
    if(v){
        memset(tree[rt].cnt, 0, sizeof tree[rt].cnt);
        tree[rt].cnt[v] = nr-nl+1;
        if(nl ^ nr)
            tree[lc].lp = tree[rc].lp = v;
        v = 0;
    }
}

void build(int l, int r, int rt = 1){
    nl = l, nr = r;
    if(l == r){
        tree[rt].cnt[a[l]] = 1;
        return;
    }
    build(l, m, lc);
    build(m+1, r, rc);
    push_up(rt);
}

void update(int l, int r, int n, int rt = 1){
    
    push_down(rt);
    
    if(r < nl || l > nr)
        return;
    
    if(l <= nl && r >= nr){
        tree[rt].lp = n;
        push_down(rt);
        return;
    }
    
    update(l, r, n, lc);
    update(l, r, n, rc);
    push_up(rt);
}

int query(int l, int r, int n, int rt = 1){
    
    if(r < nl || l > nr)
        return 0;
    
    push_down(rt);
    
    if(l <= nl && r >= nr)
        return tree[rt].cnt[n];
    
    int ret = query(l, r, n, lc) + query(l, r, n, rc);
    return ret;
}

int main(){
    
    scan(N, M, K);
    
    for(int i = 1; i <= N; i++)
        scan(a[i]);
    
    build(1, N);
    
    for(int i = 0,l,r; i < M; i++){
        memset(cnt, 0, sizeof cnt);
        scan(l, r);
        
        for(int k = 1; k <= K; k++){
            scan(order[k]);
            cnt[k] = query(l, r, k);
        }
    
        if(l == r)
            continue;
        
        int last = l;
        for(int j = 1,k; j <= K; j++){
            k = order[j];
            if(cnt[k]){
                update(last, last+cnt[k]-1, k);
                last += cnt[k];
            }
        }
    }
    
    for(int i = 1; i <= N; i++){
        for(int k = 1; k <= K; k++){
            if(query(i, i, k)){
                print(k);
                break;
            }
        }
    }
    
    return 0;
}