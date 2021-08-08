#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

using namespace std;
const int MM = 1e5+1;

random_device rd;

struct node{
    int key, pr, cnt, id;
    node *l, *r;
    node(int nkey, int i): key(nkey), pr(rd()), cnt(1), id(i), l(NULL), r(NULL){}
};

node *root[MM];
int N, M, Q, sz[MM], par[MM];

inline int cnt(node *rt){
    return rt? rt->cnt: 0;
}

inline void push_up(node *rt){
    if(rt)
        rt->cnt = cnt(rt->l) + cnt(rt->r) + 1;
}

node *right(node *rt){
    node *x = rt->l, *temp = x->r;
    x->r = rt, rt->l = temp;
    push_up(rt);
    push_up(x);
    return x;
}

node *left(node *rt){
    node *x = rt->r, *temp = x->l;
    x->l = rt, rt->r = temp;
    push_up(rt);
    push_up(x);
    return x;
}

int search(node *rt, int k){
    if(!rt)
        return -1;
    
    if(cnt(rt->l) == k)
        return rt->id;
    
    if(cnt(rt->l) > k)
        return search(rt->l, k);
    else
        return search(rt->r, k - cnt(rt->l)-1);
}

node *insert(node *rt, int key, int id){
    if(!rt)
        return new node(key, id);
    
    if(key <= rt->key){
        rt->l = insert(rt->l, key, id);
        if(rt->l->pr > rt->pr)
            rt = right(rt);
    }
    else{
        rt->r = insert(rt->r, key, id);
        if(rt->r->pr > rt->pr)
            rt = left(rt);
    }
    
    push_up(rt);
    
    return rt;
}

//what the fuck
void merge(node *rt, node *&into){
    if(!rt)
        return;
    into = insert(into, rt->key, rt->id);
    merge(rt->l, into);
    merge(rt->r, into);
}

inline int find(int x){
    while(x != par[x]){
        x = par[x];
        par[x] = par[par[x]];
    }
    return x;
}

int main(){
    
    scan(N, M);
    
    for(int i = 1,n; i <= N; i++){
        scan(n);
        root[i] = NULL;
        root[i] = insert(root[i], n, i);
        sz[i] = 1;
        par[i] = i;
    }
    
    for(int i = 0,a,b; i < M; i++){
        scan(a, b);
        
        a = find(a), b = find(b);
        if(a == b)
            continue;
        
        if(sz[a] < sz[b])
            swap(a, b);
        
        merge(root[b], root[a]);
        sz[a] += sz[b];
        par[b] = a;
    }
    
    scan(Q);
    
    for(int i = 0,a,b; i < Q; i++){
        char op;
        scanf(" %c %d %d", &op, &a, &b);
        
        if(op == 'B'){
            a = find(a), b = find(b);
            if(a == b)
                continue;
            
            if(sz[a] < sz[b])
                swap(a, b);
    
            merge(root[b], root[a]);
            sz[a] += sz[b];
            par[b] = a;
            
        }
        else{
            a = find(a);
            printf("%d\n", search(root[a], b-1));
        }
    }
    
    return 0;
}