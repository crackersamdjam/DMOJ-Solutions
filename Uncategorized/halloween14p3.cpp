#include <bits/stdc++.h>
typedef long long ll;
constexpr int MM = 5002;
const ll base = 31, mod = 1e9+7;

#include <ext/pb_ds/assoc_container.hpp>
__gnu_pbds::gp_hash_table<ll, __gnu_pbds::null_type> st;

int n, ans;
char s[MM];
ll h[MM], p[MM];

inline ll sub(int l, int r){
    ll v = (h[r] - h[l]*p[r-l])%mod;
    if(v < 0)
        v += mod;
    return v;
}

int main(){
    scanf("%s", s+1);
    n = strlen(s+1);
    p[0] = 1;
    for(int i = 1; i <= n; i++){
        p[i] = p[i-1]*base % mod;
        h[i] = (h[i-1]*base + s[i]) % mod;
    }
    for(int i = 0; i < n; i++){
        for(int j = 1; i+j+j <= n; j++){
            ll ref = sub(i, i+j);
            for(int k = i+j+j; k <= n; k += j){
                ll cur = sub(k-j, k);
                if(cur != ref)
                    break; //can no longer match with len j in future
                ll add = sub(i, k);
                st.insert(add);
            }
        }
    }
    
    printf("%ld\n", st.size());
    
    return 0;
}
/*
 * no overlaps, but may be multiples
 * each magic either string s x2, x3, x4, ...
 * no wrapping around necessary
 */