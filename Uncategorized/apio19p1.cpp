#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll A, B;
map<ll, int> mp;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>A>>B;
    ll mod = A*B/__gcd(A, B+1);
    mp[mod] = 0;
    while(n--){
        ll l, r;
        cin>>l>>r;
        if(r-l >= mod){
            cout<<mod;
            return 0;
        }
        l %= mod, r %= mod;
        if(l <= r){
            mp[l]++;
            mp[r+1]--;
        }
        else{
            mp[0]++;
            mp[r+1]--;
            mp[l]++;
        }
    }
    ll ans = 0, last = 0, sum = 0;
    for(auto i: mp){
        if(sum > 0)
            ans += i.first-last;
        sum += i.second;
        last = i.first;
    }
    cout<<ans<<'\n';
    
    return 0;
}