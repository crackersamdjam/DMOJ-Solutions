#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ld = double;
using ll = long long;
constexpr int MM = 1e5+5;

map<ll, int> mp;
int n, psa[MM];
ll l, r, y;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
    cin>>n>>l>>r>>y;
    mp[l] = mp[r+1] = 0;
    
    for(int i = 0; i < n; i++){
        ll x, v, h;
        cin>>x>>h>>v;
        
        ll xx = ceil((ld)v*y/h + x);
        mp[max(xx, l)]--;
        
        xx = floor((ld)v*-y/h + x) + 1;
        mp[max(xx, l)]++;
    }
    ll last = l, cnt = 0;
    for(auto [i, v]: mp){
        ll d = i-last;
        last = i;
        psa[cnt] += d;
        cnt += v;
        if(i == r+1) break;
    }
    cout<<psa[0]<<'\n';
    for(int i = 1; i <= n; i++){
        psa[i] += psa[i-1];
        cout<<psa[i]<<'\n';
    }
}