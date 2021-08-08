#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using piii = pair<pair<int, int>, int>;
constexpr int MM = 5e5+1, NN = 1e6+1, inf = 1e9;

struct Tree{
#define nm ((nl+nr)/2)
#define lc (rt<<1)
#define rc (rt<<1|1)
    
    int val[NN*3], DEF;
    multiset<int> st[NN];
    
    void update(int l, int v, int op, int nl = 0, int nr = NN-1, int rt = 1){
        if(l < nl or l > nr)
            return;
        if(nl == nr){
            if(op) st[l].insert(v);
            else st[l].erase(st[l].lower_bound(v));
            val[rt] = (st[l].size() ? ((DEF > 0) ? *st[l].begin() : *st[l].rbegin()) : DEF);
            return;
        }
        update(l, v, op, nl, nm, lc);
        update(l, v, op, nm+1, nr, rc);
        val[rt] = (DEF > 0) ? min(val[lc], val[rc]) : max(val[lc], val[rc]);
    }
    int querymin(int l, int r, int nl = 0, int nr = NN-1, int rt = 1){
        if(r < nl or nr < l)
            return DEF;
        if(l <= nl and nr <= r)
            return val[rt];
        return min(querymin(l, r, nl, nm, lc), querymin(l, r, nm+1, nr, rc));
    }
    int querymax(int l, int r, int nl = 0, int nr = NN-1, int rt = 1){
        if(r < nl or nr < l)
            return DEF;
        if(l <= nl and nr <= r)
            return val[rt];
        return max(querymax(l, r, nl, nm, lc), querymax(l, r, nm+1, nr, rc));
    }
#undef nm
#undef lc
#undef rc
} MINR, MAXL;

int q, l[MM], r[MM], in[MM], t;
multiset<pii> ans;
set<piii> ins;
int lastans[MM];

int update(int i){
    if(lastans[i])
        ans.erase(ans.lower_bound({lastans[i], i}));
    
    if(!in[i]){
        lastans[i] = 0;
        return 0;
    }
    
    int a = l[i], b = r[i];
    int v = min(MINR.querymin(b, NN-1)-a, b-MAXL.querymax(0, a));
    
    lastans[i] = v;
    ans.insert({v, i});
    
    return v;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    MINR.DEF = inf;
    MAXL.DEF = -inf;
    for(int i = 0; i < NN*3; i++){
        MINR.val[i] = inf;
        MAXL.val[i] = -inf;
    }
    
    cin>>q;
    while(q--){
        char op;
        int a, b;
        cin>>op>>a>>b;
        if(op == 'A'){
            in[t] = 1;
            l[t] = a, r[t] = b;
            ins.insert({{a, b}, t});
            update(t);
        
            MINR.update(a, b, 1);
            MAXL.update(b, a, 1);
            t++;
        }
        else{
            MINR.update(a, b, 0);
            MAXL.update(b, a, 0);
        
            auto rm = ins.lower_bound({{a, b}, 0});
            in[rm->second] = 0;
            update(rm->second);
            ins.erase(rm);
        }
    
        //there is overlap in all
        int hil = MAXL.querymax(0, NN-1);
        int lor = MINR.querymin(0, NN-1);
        
        if(hil < lor){
            //get overlap
            int rs = MINR.querymin(hil, hil);
            int ls = MAXL.querymax(lor, lor);
            cout<<rs-ls<<'\n';
        }
        else{
            auto best = *ans.begin();
            while(1){
                if(update(best.second) == best.first)
                    break;
                best = *ans.begin();
            }
            cout<<best.first<<'\n';
        }
    }
}