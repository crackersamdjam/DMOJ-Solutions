#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
const int MM = 5e5+5;

struct st{
    int p, v, i;
    bool operator<(const st &o) const{
        return p < o.p;
    }
} a[MM];

int n, ls[MM], rs[MM], ans[MM];

void update(int i, int v, int *bit){
    for(; i < MM; i += i&-i)
        bit[i] += v;
}

int query(int i, int *bit){
    int ret = 0;
    for(; i; i -= i&-i)
        ret += bit[i];
    return ret;
}

void go(vector<st> &v, int l, int r){
    if(v.empty() or l >= r)
        return;
    vector<st> vl, vr;
    int m = (l+r)/2;
    for(auto &i: v){
        if(i.i <= m){
            ans[i.p] += query(i.v-1, rs);
            //tot greater ind and less val
            update(i.v, 1, ls);
            vl.push_back(i);
        }
        else{
            ans[i.p] += vl.size()-query(i.v, ls);
            //tot less ind and  greater val
            update(i.v, 1, rs);
            vr.push_back(i);
        }
    }
    for(auto &i: v){
        if(i.i <= m)
            update(i.v, -1, ls);
        else
            update(i.v, -1, rs);
    }
    go(vl, l, m);
    go(vr, m+1, r);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i].v;
        a[i].i = i;
    }
    vector<st> v;
    for(int i = 1,p; i <= n; i++){
        cin>>p;
        a[p].p = i;
        v.push_back(a[p]);
    }
    sort(all(v));
    go(v, 1, n);

    long long sum = 0;
    for(int i = 1; i <= n; i++){
        sum += ans[i];
        cout<<sum<<'\n';
    }
    
    return 0;
}