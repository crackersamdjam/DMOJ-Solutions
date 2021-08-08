#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4,popcnt,abm,mmx,tune=native")
#include <bits/stdc++.h>
using ll = long long;
const int MM = 1e6+1, LOG = 20;

int n, k, sp[LOG][MM], q[MM], l, r, q2[MM], l2, r2;
ll dp[MM];

ll max(ll a, ll b){
    return a > b ? a : b;
}

int rmq(int a, int b){
    int kl = 31-__builtin_clz(b-a+1);
    return max(sp[kl][a], sp[kl][b-(1<<kl)+1]);
}

ll val(int j, int i){
    return dp[j] + rmq(j+1, i);
}

int main(){
    std::cin.sync_with_stdio(0);
    std::cin.tie(0);
    std::cin >> n >> k;
    
    for(int i = 1; i <= n; i++)
        std::cin >> sp[0][i];
    
    if(k == 1)
        return std::cout << std::accumulate(sp[0], sp[0]+n+1, 0LL) << '\n', 0;
    
    for(int j = 1; j <= 31-__builtin_clz(n); j++)
        for(int i = 0; i+(1<<j)-1 <= n; i++)
            sp[j][i] = max(sp[j-1][i], sp[j-1][i+(1<<(j-1))]);
    
    for(int i = 1; i <= n; i++){
        if(i % k == 1){
            //recalc
            l = l2 = 1, r = r2 = 0;
            for(int j = max(0, i-k); j < i; j++){
                while(l <= r and val(q[r], i) < val(j, i))
                    r--;
                q[++r] = j;
                
                while(l2 <= r2 and dp[q2[r2]] < dp[j])
                    r2--;
                q2[++r2] = j;
            }
        }
        
        if(i-q[l] > k)
            l++;
        if(i-q2[l2] > k)
            l2++;
        
        while(l < r and val(q[l], i) <= val(q[l+1], i))
            l++;
        while(l2 < r2 and val(q2[l2], i) <= val(q2[l2+1], i))
            l2++;
        
        dp[i] = max(val(q[l], i), val(q2[l2], i));
        
    }
    
    std::cout << dp[n] << '\n';
    
    return 0;
}
/*
[  day k ][ day k+1  ]
when we recalculate deques for dp, the rmq of (j in day k) to (i in day k+1)
 will return a value of the max #, which is either in [day k] or [day k+1]
 if in [day k+1], we choose best dp[j]
 if in [day k], we choose best dp[j] + rmq(j, first_of_day_k+1)
 */