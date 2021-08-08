#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MM = 1e5+5;

int n, k, a[MM], cnt[MM];
ll dp[MM];

void go(ll c){
    for(int i = 2; i <= n; i++){
        ll v = dp[i-2] + a[i] - a[i-1] - c;
        if(dp[i-1] < v){
            dp[i] = dp[i-1];
            cnt[i] = cnt[i-1];
        }
        else{
            dp[i] = v;
            cnt[i] = cnt[i-2]+1;
        }
    }
}

int main(){
    cin>>n>>k;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    
    ll l = 0, m, r = 1e9;
    while(l <= r){
        m = (l+r)/2;
        go(m);
        if(cnt[n] < k)
            l = m+1;
        else
            r = m-1;
    }
    go(l);
    
    cout << dp[n]+k*l << '\n';
    
    return 0;
}