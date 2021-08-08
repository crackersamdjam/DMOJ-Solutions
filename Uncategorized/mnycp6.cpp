#include <bits/stdc++.h>
using namespace std;
const int MM = 10002;
struct st{
    int l,r,val;
} tree[4*MM];
int C,N;
char op;
string stra, strb;
unordered_map<string,int> pos;
inline int valOf(string str){
    int ret = 0;
    for(int i = 0; i < str.length(); i++)
        ret += str[i] - 'a' + 1;
    return ret;
}
inline void push_up(int rt){
    tree[rt].val = tree[rt<<1].val + tree[rt<<1 | 1].val;
}
void build(int rt, int l, int r){
    tree[rt].l = l, tree[rt].r = r;
    if(l == r)
        return;
    int m = (l+r)>>1;
    build(rt<<1, l, m);
    build(rt<<1 | 1, m+1, r);
}
void update(int rt, int ind, int val){
    int l = tree[rt].l, r = tree[rt].r;
    if(l == r){
        tree[rt].val += val;
        return;
    }
    int m = (l+r)>>1;
    if(ind <= m)
        update(rt<<1, ind, val);
    else
        update(rt<<1 | 1, ind, val);
    push_up(rt);
}
int query(int rt, int l, int r){
    int nl = tree[rt].l, nr = tree[rt].r;
    
    if(l <= nl && r >= nr)
        return tree[rt].val;
    if(r < nl || l > nr)
        return 0;
    
    return query(rt<<1, l, r) + query(rt<<1 | 1, l, r);
}
int main(){
    build(1, 1, MM-2);
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> C;
    for(int i = 0,va,vb,pa,pb; i < C; i++){
        cin >> op;
        if(op == 'N'){
            cout << N << '\n';
            continue;
        }
        cin >> stra;
        va = valOf(stra);
        if(op == 'A'){
            if(pos[stra]){
                cout << "Can't add " << stra << '\n';
                continue;
            }
            pos[stra] = ++N;
            update(1, N, va);
            continue;
        }
        cin >> strb;
        vb = valOf(strb);
        
        if(op == 'S'){
            pa = pos[stra], pb = pos[strb];
            pos[stra] = pb;
            pos[strb] = pa;
            update(1, pa, vb - va);
            update(1, pb, va - vb);
        }else if(op == 'M'){
            pa = pos[stra], pb = pos[strb];
            if(pb < pa){
                int pc = pa;
                pa = pb;
                pb = pc;
            }
            cout << query(1, pa, pb) << '\n';
        }else{
            pa = pos[stra];
            pos[stra] = 0;
            pos[strb] = pa;
            update(1, pa, vb - va);
        }
    }
    return 0;
}