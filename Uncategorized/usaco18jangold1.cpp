#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+1;

int n, q, par[MM], sz[MM], ans[MM];
struct sta{
    int a, b, c;
    bool operator<(const sta &o) const{
        return c > o.c;
    }
};
vector<sta> v;
struct st{
    int u, k, i;
    bool operator<(const st &o) const{
        return k > o.k;
    }
};
vector<st> qu;

int find(int x){
    while(x != par[x])
        x = par[x], par[x] = par[par[x]];
    return x;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    v.resize(n-1);
    for(int i = 0; i < n-1; i++){
        cin >> v[i].a >> v[i].b >> v[i].c;
    }
    sort(v.begin(), v.end());
    
    for(int i = 1; i <= n; i++)
        par[i] = i, sz[i] = 1;
    
    qu.resize(q);
    for(int i = 0; i < q; i++){
        cin >> qu[i].k >> qu[i].u;
        qu[i].i = i;
    }
    
    sort(qu.begin(), qu.end());
    
    int l = 0;
    for(auto p: qu){
        while(l < n-1 and v[l].c >= p.k){
            //cout << "l " << l << '\n';
            int a = find(v[l].a), b = find(v[l].b);
            if(a != b){
                par[a] = b;
                sz[b] += sz[a];
            }
            l++;
        }
        //cout << p.k << ' ' << p.u << ' ' << find(p.u) << '\n';
        ans[p.i] = sz[find(p.u)]-1;
    }
    
    for(int i = 0; i < q; i++)
        cout << ans[i] << '\n';
    
    return 0;
}