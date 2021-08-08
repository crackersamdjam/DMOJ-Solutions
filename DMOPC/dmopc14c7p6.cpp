#include <bits/stdc++.h>
#define lc (rt<<1)
#define rc (rt<<1|1)
#define m ((nl+nr)>>1)
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

using namespace std;
const int MM = 1e5+2;

int N, a[MM];

struct node{
    int sum, ps;
} tree[MM*3];

inline void push_up(int rt){
    tree[rt].sum = tree[lc].sum + tree[rc].sum;
    tree[rt].ps = min(tree[lc].ps, tree[lc].sum + tree[rc].ps);
}

void update(int pos, int val, int nl = 1, int nr = MM-1, int rt = 1){
    if(nl == nr){
        tree[rt].sum = tree[rt].ps = val;
        return;
    }
    if(pos <= m)
        update(pos, val, nl, m, lc);
    else
        update(pos, val, m+1, nr, rc);
    push_up(rt);
}

inline int query(){
    return tree[1].ps;
}

int main(){
    
    int ans = 0;
    
    scan(N);
    
    for(int i = 1; i <= N; i++)
        scan(a[i]);
    
    update(a[1], -1);
    update(a[2], 1);
    
    if(query() >= 0)
        ans = 1;
    
    for(int i = 2; i <= N/2; i++){
        update(a[i], -1);
        update(a[(i<<1)-1], 1);
        update(a[i<<1], 1);
        
        if(query() >= 0)
            ans = i;
    }
    
    print(ans);
    
    return 0;
}