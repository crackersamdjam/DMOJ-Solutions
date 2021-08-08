#include <bits/stdc++.h>
using ll = long long;

ll n, k, m;

bool go(ll x){
    ll cnt = 0, rem = n;
    while(rem > 0){
        ll y = rem/x;
        if(y <= m)
            break;
        
        ll lo = x*y;
        //changes after lo
        ll dif = (rem-lo)/y+1; //y this # of times
        rem -= dif*y;
        cnt += dif;
    }
    ll rm = (rem-1)/m+1;
    cnt += rm;
    //printf("%lld, %lld %lld\n", x, cnt, k);
    return cnt <= k;
}

int main(){
    scanf("%lld %lld %lld",&n,&k,&m);
    ll l = 1, mid, r = 1e14;
    while(l <= r){
        mid = (l+r)/2;
        if(go(mid))
            l = mid+1;
        else
            r = mid-1;
    }
    printf("%lld", r);
    
    return 0;
}