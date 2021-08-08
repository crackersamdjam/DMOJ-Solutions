#include <bits/stdc++.h>
using namespace std;
using st = pair<int, pair<int, int>>;
const int MM = 6e5+5;

seed_seq seq {
(uint64_t)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count(),
(uint64_t)__builtin_ia32_rdtsc(),(uint64_t)(uintptr_t)make_unique<char>().get()
};
mt19937_64 rng64(seq);
uniform_int_distribution<long long> dis;
struct stc{
    int t, pnum, num, id;
};
using Data = stc; //order inserted, problem id, # of solves, person id
using Lazy = int; const Data vdef = {0, 0, 0, 0}, qdef = {0, 0, 0, 0};
Data merge(const Data &l, const Data &r){
    return l; //idc
}
Data applyLazy(const Data &l, const Lazy &r){
    return l; //idc
}
struct Node {
    Node *l, *r;
    Node *p;
    int size; long long pri; Data val, sbtr;
    int kms;
    Node(const Data &val) : l(nullptr), r(nullptr),
                            p(nullptr),
                            size(1), pri(dis(rng64)), val(val), sbtr(val), kms(0) {}
    void update() {
        size = !kms; sbtr = val;
        if (l) {
            l->p = this;
            size += l->size; sbtr = merge(l->sbtr, sbtr);
        }
        if (r) {
            r->p = this;
            size += r->size; sbtr = merge(sbtr, r->sbtr);
        }
    }
    void apply(const Lazy &v) { val = applyLazy(val, v); sbtr = applyLazy(sbtr, v); }
};
int Size(Node *x) { return x ? x->size : 0; }
Data Val(Node *x) { return x ? x->val : vdef; }
Data Sbtr(Node *x) { return x ? x->sbtr : qdef; }
void merge(Node *&x, Node *l, Node *r){
    if (!l || !r) { x = l ? l : r; }
    else if (l->pri > r->pri) { merge(l->r, l->r, r); x = l; }
    else { merge(r->l, l, r->l); x = r; }
    if (x) x->update();
}
void split(Node *x, Node *&l, Node *&r, int lsz) {
    if (!x) { l = r = nullptr; return; }
    x->p = nullptr;
    if (lsz <= Size(x->l)) { split(x->l, l, x->l, lsz); r = x; }
    else { split(x->r, x->r, r, lsz - Size(x->l) - (!x->kms)); l = x; } //if empty node, don't sub one again
    x->update();
}
/*
Node *select(Node *x, int k) { // 0-indexed
    if (!x) return nullptr;
    int t = Size(x->l);
    if (t > k) return select(x->l, k);
    else if (t < k) return select(x->r, k - t - (!x->kms);
    return x;
}*/
void rm(Node *x){
    for(; x; x = x->p)
        x->update();
}

int n, m, k, cnt[MM];
bool vis[MM], vis2[MM];
Node *last[MM];
vector<pair<int, pair<int, int>>> out[MM];
vector<int> vv;

void inorder(Node *x){
    if(x->l) inorder(x->l);
    int id = x->val.id;
    if(id != 0){
        if(!vis2[id]){
            vis2[id] = 1;
            vv.emplace_back(id);
        }
    }
    if(x->r) inorder(x->r);
}

int maxx, sum[MM], ID;

void inorder2(Node *x){
    if(x->l) inorder2(x->l);
    int id = x->val.id;
    if(id != 0 and x->val.num == ID){
        int tp = x->val.t*10 + sum[id], pn = 0;
        if(tp <= maxx){
            int dif = maxx+1-tp;
            int sub = (dif+9)/10;
            tp += 10*sub;
            pn = sub;
        }
        maxx = tp;
        sum[id] = tp;
        int problem = x->val.pnum;
        out[id].push_back({problem, {10*x->val.t, pn}});
    }
    if(x->r) inorder2(x->r);
}

int main(){
    scanf("%d%d%d", &n, &m, &k);
    Node *rt = new Node({0, 0, 0, 0});
    for(int i = 1,c,p,r; i <= k; i++){
        scanf("%d%d%d", &c, &p, &r);
        
        if(cnt[c]){
            //remove old one
            last[c]->kms = 1;
            //update sizes of all above
            rm(last[c]);
        }
        cnt[c]++;
        
        Node *ls, *rs;
        split(rt, ls, rs, r);
        last[c] = new Node({i, p, cnt[c], c});
        merge(ls, ls, last[c]);
        merge(rt, ls, rs);
        vis[c] = 1;
    }
    inorder(rt);
    //to get output order
    
    for(ID = 1; ID <= m; ID++){
        maxx = 0;
        inorder2(rt);
    }
    
    for(auto i: vv){
        printf("%d", i);
        for(int j = 1; j <= m; j++){
            bool b = 0;
            for(auto p: out[i]){
                if(p.first == j){
                    assert(p.second.first > 0);
                    assert(p.second.first <= 10000000);
                    assert(p.second.second >= 0);
                    assert(p.second.second < 10000000);
                    printf(" %d/%d", p.second.first, p.second.second);
                    b = 1;
                }
            }
            if(!b)
                printf(" -/-");
        }
        printf("\n");
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            printf("%d", i);
            for(int j = 0; j < m; j++)
                printf(" -/-");
            printf("\n");
        }
    }
    
    return 0;
}