#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MM = 1e6+5;

int n;
ll a[MM];
ll dp[MM], c;

struct ln{
    ll m, b;
    ll f(ll x){
        return m*x+b;
    }
} tree[MM*3];

void add(ln ln, int l = 0, int r = MM-1, int rt = 1){
    int m = (l+r)/2;
    bool bl = ln.f(l) < tree[rt].f(l);
    bool bm = ln.f(m) < tree[rt].f(m);
    if(bm)
        swap(tree[rt], ln);
    //ln is higher one as passes m, so ln will only be updated on left or right side
    if(l == r)
        return;
    if(bl != bm)
        add(ln, l, m, rt<<1);
    else
        add(ln, m+1, r, rt<<1|1);
}

ll query(ll x, int l = 0, int r = MM-1, int rt = 1){
    int m = (l+r)/2;
    if(l == r)
        return tree[rt].f(x);
    if(x <= m)
        return min(tree[rt].f(x), query(x, l, m, rt<<1));
    return min(tree[rt].f(x), query(x, m+1, r, rt<<1|1));
}

int main(){
    cin>>n>>c;
    cin>>a[1];
    add({-2*a[1], a[1]*a[1]});
    
    for(int i = 2; i <= n; i++){
        cin>>a[i];
        dp[i] = query(a[i]) + a[i]*a[i] + c;
        add({-2*a[i], a[i]*a[i]+dp[i]});
    }
    
    cout<<dp[n]<<'\n';
    
    return 0;
}
/*
 
 dp[i] = dp[j] + (a[i]-a[j])^2 + c
 dp[i] = dp[j] + a[i]^2 + a[j]^2 - 2a[i]a[j] + c
 
 */