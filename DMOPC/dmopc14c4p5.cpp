#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MM = 2e5+5, F = 5;

int n, k, a[MM];
ll bitl[MM*F], bitr[MM*F];
ll ans = LLONG_MAX, suml[MM*F], sumr[MM*F], totl, totr;

void update(int j, ll v, ll *bit, ll *sum, ll &tot){
    tot += j*v;
    for(int i = j+MM+MM; i < MM*F; i += i&-i){
        bit[i] += v;
        sum[i] += j*v;
    }
}

// l a[i]-i, r a[i]+i

void ul(int i, ll v){
    update(a[i]-i, v, bitl, suml, totl);
}

void ur(int i, ll v){
    update(a[i]+i, v, bitr, sumr, totr);
}

ll query(int i, ll *bit){
    ll ret = 0;
    for(i += MM+MM; i; i -= i&-i)
        ret += bit[i];
    return ret;
}

void go(int i){
    if(i+i-1 < k)
        return;
    //bs for median
    int l = -MM, m, r = MM+MM-2;
    while(l <= r){
        m = (l+r)/2;
        
        ll lm = m-i, rm = m+i;
        
        ll lc = query(lm, bitl);
        ll rc = query(rm, bitr);
        
        ll lsum = query(lm, suml);
        ll rsum = query(rm, sumr);
        
        ll v = (lc*lm - lsum) + (totl-lsum - (i-lc)*lm) + (rc*rm-rsum) + (totr-rsum - (i-1-rc)*rm);
        if(v < ans){
            ans = v;
        }
        
        int tot = i+i-1, cnt = lc+rc;
        if(cnt*2 > tot)
            r = m-1;
        else
            l = m+1;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    
    if(k == 1){
        cout<<0;
        return 0;
    }
    
    ul(1, 1);
    ul(2, 1);
    ur(3, 1);
    
    for(int i = 2; i <= n; i++){
        if(i+i-1 > n) break;
        
        if(i > 2){
            ur(i, -1);
            ul(i, 1);
            ur(i+i-2, 1);
            ur(i+i-1, 1);
        }
        
        go(i);
    }
    if(ans == LLONG_MAX)
        ans = -1;
    cout<<ans<<'\n';
}