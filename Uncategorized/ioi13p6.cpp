#pragma GCC optimize "Ofast"
#pragma GCC target "sse4"
#include <bits/stdc++.h>
typedef long long ll;

std::mt19937 gen(time(0));
std::uniform_int_distribution<int> dis;
ll algo_gcd(ll gcd_a, ll gcd_b){return gcd_b == 0 ? gcd_a : algo_gcd(gcd_b, gcd_a % gcd_b);}

struct tnode{
    int key, pr;
    ll val, gcd;
    tnode *l, *r;
    tnode(int key, ll val){
        this->key = key;
        this->val = this->gcd = val;
        pr = dis(gen);
        l = r = nullptr;
    }
};

inline void upd(tnode *rt){
    if(rt)
        rt->gcd = algo_gcd(rt->l ? rt->l->gcd : 0, algo_gcd(rt->val, rt->r ? rt->r->gcd : 0));
}

void split(tnode *cur, int key, tnode *&l, tnode *&r){
    if(!cur){
        l = r = nullptr;
        return;
    }
    if(cur->key > key){
        split(cur->l, key, l, cur->l);
        r = cur;
    }
    else{
        split(cur->r, key, cur->r, r);
        l = cur;
    }
    upd(cur);
}

void merge(tnode *&cur, tnode *l, tnode *r){
    if(!l || !r)
        cur = l ? l : r;
    else if(l->pr > r->pr){
        merge(l->r, l->r, r);
        cur = l;
    }
    else{
        merge(r->l, l, r->l);
        cur = r;
    }
    upd(cur);
}

void insert(tnode *&cur, tnode *tnode, bool exist){
    if(!cur)
        cur = tnode;
    else if(cur->key == tnode->key)
        cur->val = tnode->val;
    else if(!exist && cur->pr > tnode->pr){
        split(cur, tnode->key, tnode->l, tnode->r);
        cur = tnode;
    }
    else
        insert(tnode->key < cur->key? cur->l : cur->r, tnode, exist);
    upd(cur->l);
    upd(cur->r);
    upd(cur);
}

bool exist(tnode *cur, int k){
    if(!cur)
        return 0;
    if(cur->key == k)
        return 1;
    if(cur->key > k)
        return exist(cur->l, k);
    return exist(cur->r, k);
}

ll index(tnode *cur, int k){
    if(!cur)
        return 0;
    if(cur->key == k)
        return cur->val;
    if(cur->key > k)
        return index(cur->l, k);
    return index(cur->r, k);
}

struct node{
    node *l, *r;
    tnode *rt;
    
    void update(int nl, int nr, int i, int j, ll v){
        
        if(nl == nr){
            insert(rt, new tnode(j, v), exist(rt, j));
            return;
        }
        
        int nm = (nl+nr)/2;
        
        if(i <= nm){
            if(!l) l = new node();
            l->update(nl, nm, i, j, v);
        }
        else{
            if(!r) r = new node();
            r->update(nm+1, nr, i, j, v);
        }
        if(rt)
            insert(rt, new tnode(j, algo_gcd(l ? index(l->rt, j) : 0, r ? index(r->rt, j) : 0)), exist(rt, j));
        else
            insert(rt, new tnode(j, v), 0);
    }
    
    ll query(int nl, int nr, int lx, int rx, int ly, int ry){
        
        if(rx < nl || lx > nr)
            return 0;
        
        if(lx <= nl && nr <= rx){
            tnode *a, *b, *c;
            split(rt, ly-1, a, b);
            split(b, ry, b, c);
            ll ret = b ? b->gcd : 0;
            merge(b, b, c);
            merge(rt, a, b);
            return ret;
        }
        
        int nm = (nl+nr)/2;
        return algo_gcd(l? l->query(nl, nm, lx, rx, ly, ry) : 0, r? r->query(nm+1, nr, lx, rx, ly, ry) : 0);
    }
    
} segrt;

int n, m;

void init(int r, int c){
    n = r, m = c;
}

void update(int i, int j, ll k){
    segrt.update(0, n-1, i, j, k);
}

ll calculate(int lx, int ly, int rx, int ry){
    return segrt.query(0, n-1, lx, rx, ly, ry);
}