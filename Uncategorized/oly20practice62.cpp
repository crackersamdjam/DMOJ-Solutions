#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;

int n;
ll m;
ll a[44];
vector<ll> vec;

int main(){
    cin>>n>>m;
    for(int i = 0; i < n; i++)
        cin>>a[i];
    int f = n/2, s = n-f;
    for(int i = 0; i < (1<<f); i++){
        ll v = 0;
        for(int j = 0; j < f; j++){
            if(i&(1<<j))
                v += a[j];
        }
        vec.emplace_back(v);
    }
    sort(all(vec));
    ll ans = 0;
    for(int i = 0; i < (1<<s); i++){
        ll v = 0;
        for(int j = 0; j< s; j++){
            if(i&(1<<j))
                v += a[f+j];
        }
        ans += upper_bound(all(vec), m-v) - vec.begin();
    }
    
    cout<<ans;
}