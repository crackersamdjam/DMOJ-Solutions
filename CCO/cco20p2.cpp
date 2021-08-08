#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using pii = pair<int, int>;
using ll = long long;
const int MM = 2e5+5;

pii inf = {1e9, 0};
int n, par[MM], a[MM], b[MM], in[MM], out[MM], bit[MM];
ll ans;

int find(int x){
    while(x != par[x])
        x = par[x], par[x] = par[par[x]];
    return x;
}

void add(int i){
    for(; i < MM; i += i&-i)
        bit[i]++;
}

int query(int i){
    int ret = 0;
    for(; i; i -= i&-i)
        ret += bit[i];
    return ret;
}

struct Tree{
#define nm ((nl+nr)/2)
#define lc (rt<<1)
#define rc (rt<<1|1)
    
    struct node{
        pii val;
        int lp;
    } tree[MM*3];
    
    void pull(int rt){
        tree[rt].val = min(tree[lc].val, tree[rc].val);
    }
    
    void push(int nl, int nr, int rt){
        if(nl == nr)
            return;
        int &vv = tree[rt].lp;
        tree[lc].val.first += vv;
        tree[rc].val.first += vv;
        tree[lc].lp += vv;
        tree[rc].lp += vv;
        
        vv = 0;
    }
    
    void edit(int l, int r, pii nv, int nl = 1, int nr = n, int rt = 1){
        push(nl, nr, rt);
        if(r < nl or l > nr)
            return;
        if(l <= nl and nr <= r){
            tree[rt].val = nv;
            return;
        }
        edit(l, r, nv, nl, nm, lc);
        edit(l, r, nv, nm+1, nr, rc);
        pull(rt);
    }
    
    void update(int l, int r, int nl = 1, int nr = n, int rt = 1){
        push(nl, nr, rt);
        if(r < nl or l > nr)
            return;
        if(l <= nl and nr <= r){
            tree[rt].val.first--; //need to move left one more
            tree[rt].lp--;
            return;
        }
        update(l, r, nl, nm, lc);
        update(l, r, nm+1, nr, rc);
        pull(rt);
    }
    
    pii query(){
        return tree[1].val;
    }
} ST;

set<int> no;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 1; i <= n; i++){
        par[i] = i;
        cin>>b[i];
        a[i] = b[i];
        
        ST.edit(i, i, {b[i]-i, i});
        no.insert(i);
    }
    sort(b+1, b+n+1);
    for(int i = 1; i <= n; i++){
        if(i > b[i]){
            cout<<"-1";
            return 0;
        }
    }
    
    //par on values
    for(int i = n; i; i--){
        int nv = find(a[i]);
        a[i] = nv;
        par[nv] = find(nv-1);
    }
//    for(int i = 1; i <= n; i++)
//        cout<<a[i]<<' ';
//    cout<<"\n\n";
    
    for(int i = 0; i <= n; i++)
        par[i] = i;
    
    
    while(1){
        int v = ST.query().first, i = ST.query().second;
//        cout<<"try "<<v<<' '<<i<<endl;
        if(v >= 0)
            break;
        no.erase(i);
    
        int ind = find(a[i]); //first one left of a[i]
//        cout<<"rm "<<v<<' '<<i<<' '<<a[i]<<' '<<ind<<endl;
        assert(ind > 0);
        out[ind] = i;
        par[ind] = find(ind-1);
        
        ST.edit(i, i, inf);
//        cout<<"sub "<<ind<<' '<<i<<endl;
        ST.update(ind, i);
        //
    }
    
    vector<pii> vv;
    for(int i: no)
        vv.emplace_back(a[i], i);
    sort(all(vv));
    for(auto i: vv){
        int ind = find(i.first);
        out[ind] = i.second;
        par[ind] = find(ind-1);
    }
    
    for(int i = 1; i <= n; i++){
//        if(!out[i]){
//            out[i] = *no.begin();
//            no.erase(no.begin());
//        }
        
        ans += i-1-query(out[i]);
        add(out[i]);
        
//        cout<<a[out[i]]<<' ';
//        cout<<out[i]<<' ';
    }
    
    cout<<ans<<'\n';
}
/*

4
4 4 3 2
3

3
1 1 3
-1

8
3 8 5 8 6 3 1 6
 
 */