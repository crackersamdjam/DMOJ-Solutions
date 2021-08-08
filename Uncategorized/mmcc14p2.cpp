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
const int MN = 2001, MM = 5001, base = 131, b2 = 193;

int N, M, Q, id[MN], lcp[MN][MN];
ll val[MN][MM], v2[MN][MM];

#define lc (rt<<1)
#define rc (rt<<1|1)
#define nl tree[rt].l
#define nr tree[rt].r
#define nm ((nl+nr)>>1)

struct node{
    int l, r, min;
} tree[MN*3];

void push_up(int rt){
    tree[rt].min = min(min(tree[lc].min, tree[rc].min), lcp[id[nm]][id[nm+1]]);
}

void build(int l = 0, int r = N-1, int rt = 1){
    nl = l, nr = r;
    
    if(l == r){
        tree[rt].min = M;
        return;
    }
    
    build(l, nm, lc);
    build(nm+1, r, rc);
    push_up(rt);
}

int query(int l, int r, int rt = 1){
    
    if(l <= nl && nr <= r )
        return tree[rt].min;
    
    if(r <= nm)
        return query(l, r, lc);
    else if(l > nm)
        return query(l, r, rc);
    return min(min(query(l, r, lc), query(l, r, rc)), lcp[id[nm]][id[nm+1]]);
}

void update(int l, int rt = 1){
    
    if(l == nl && l == nr)
        return;
    
    update(l, (l <= nm)? lc: rc);
    push_up(rt);
}

int main(){
    
    scan(N, M);
    
    for(int i = 0; i < N; i++){
        id[i] = i;
        v2[i][0] = val[i][0] = gc-'0';
        for(int j = 1; j < M; j++){
            int nc = gc;
            val[i][j]  = val[i][j-1]*base + nc-'0';
            v2[i][j] = v2[i][j-1]*b2+nc-'0';
        }
        assert(gc == 10);
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int l = 0, m, r = M-1;
            while(l <= r){
                m = (l+r)/2;
                if(val[i][m] == val[j][m] && v2[i][m] == v2[j][m])
                    l = m+1;
                else
                    r = m-1;
            }
            lcp[j][i] = r+1;
        }
    }
    
    build();
    
    scan(Q);
    
    for(int t = 0,f,s; t < Q; t++){
        scan(f, s);
        f--, s--;
        
        print((s-f+1)*query(f, s));
        
        swap(id[f], id[s]);
        
        update(f);
        update(s);
    }
    
    
    return 0;
}