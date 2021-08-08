#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#include <bits/stdc++.h>
using ll = long long;
constexpr int MM = 30000000;
ll dp[MM];

ll go(int n){
    bool b = n < MM;
    if(b and dp[n])
        return dp[n];
    ll ret = 0;
    int k = n, v = 1;
    //for some reason looping k down is faster than looping k up
    while(k > 1){
        int nk = n/(v+1);
        ret += go(v)*(k-nk);
        v = n/nk;
        k = nk;
    }
    if(b)
        dp[n] = ret;
    return ret;
}

int main(){
    dp[1] = dp[2] = 1;
    int n;
    scanf("%d", &n);
    printf("%lld\n", go(n));
    
    return 0;
}