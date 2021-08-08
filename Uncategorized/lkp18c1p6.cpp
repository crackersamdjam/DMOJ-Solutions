#include <bits/stdc++.h>
#define lc (rt<<1)
#define rc (rt<<1|1)
#define m ((tree[rt].l + tree[rt].r)>>1)
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

using namespace std;
typedef long long ll;
const int MM = 2e5+2;

ll sum, ans[MM];
int N, M;
map<int, int> my;

struct node{
    int l, r;
    ll max;
} mintree[MM*3], maxtree[MM*3];

inline void push_up(node (&tree)[MM*3], int rt){
    tree[rt].max = max(tree[lc].max, tree[rc].max);
}

void build(node (&tree)[MM*3], int l, int r, int rt = 1){
    tree[rt].l = l, tree[rt].r = r;
    if(l == r){
        tree[rt].max = -1e10;
        return;
    }
    build(tree, l, m, lc);
    build(tree, m+1, r, rc);
    push_up(tree, rt);
}

void update(node (&tree)[MM*3], int pos, ll val, int rt = 1){
    
    if(tree[rt].l == tree[rt].r){
        tree[rt].max = val;
        return;
    }
    update(tree, pos, val, pos <= m? lc: rc);
    push_up(tree, rt);
}

ll query(node (&tree)[MM*3], int l, int r, int rt = 1){
    
    if(l > tree[rt].r || r < tree[rt].l)
        return -1e10;
    
    if(tree[rt].l == l && tree[rt].r == r)
        return tree[rt].max;
    
    if(r <= m)
        return query(tree, l, r, lc);
    else if(l > m)
        return query(tree, l, r, rc);
    else
        return max(query(tree, l, m, lc), query(tree, m+1, r, rc));
}

struct st{
    int x, y, ny, t;
    friend bool operator<(const st &f, const st &s){
        if(f.x ^ s.x)
            return f.x < s.x;
        return f.y > s.y;
    }
} a[MM];

int main(){
    
    scan(N);
    
    for(int i = 0; i < N; i++){
        scan(a[i].x, a[i].y);
        a[i].t = 0;
    }
    
    scan(M);
    
    for(int i = N; i < N+M; i++){
        scan(a[i].x, a[i].y);
        a[i].t = 1;
    }
    
    sort(a, a+N+M);
    
    for(int i = 0; i < N+M; i++)
        my[a[i].y] = 0;
    
    int t = 0;
    for(auto &itr: my)
        itr.second = ++t;
    
    build(mintree, 1, MM-1);
    build(maxtree, 1, MM-1);
    
    for(int i = 0; i < N+M; i++){
        a[i].ny = my[a[i].y];
        if(a[i].t == 0){
            ans[i] = min(a[i].x - a[i].y - query(mintree, a[i].ny, MM-1), a[i].x + a[i].y - query(maxtree, 1, a[i].ny));
        }
        else{
            update(mintree, a[i].ny, a[i].x - a[i].y);
            update(maxtree, a[i].ny, a[i].x + a[i].y);
        }
    }
    
    build(mintree, 1, MM-1);
    build(maxtree, 1, MM-1);
    
    for(int i = N+M-1; i >= 0; i--){
        if(a[i].t == 0){
            ans[i] = min(ans[i], min(-a[i].x - a[i].y - query(mintree, a[i].ny, MM-1), a[i].y - a[i].x - query(maxtree, 1, a[i].ny)));
            sum += ans[i];
        }
        else{
            update(mintree, a[i].ny, -a[i].x - a[i].y);
            update(maxtree, a[i].ny, a[i].y - a[i].x);
        }
    }
    
    print(sum);
    
    
    return 0;
}