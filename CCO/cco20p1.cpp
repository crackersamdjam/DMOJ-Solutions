#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
const int MM = 1e5+5;

map<ll, int> mp;
int n, psa[MM];
ll l, r, y;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>l>>r>>y;
    mp[l] = mp[r+1] = 0;
    
    for(int i = 0; i < n; i++){
        ll x, v, h;
        cin>>x>>v>>h;
        swap(v, h);
//        cout<<"pt "<<x<<' '<<v<<' '<<h<<endl;
        
        //rs
        ll xx = ceil((ld)v*y/h + x);
        xx = max(xx, l);
        if(xx <= r){
            mp[xx]--;
        }
        
        //ls
        xx = floor((ld)v*-y/h + x + 1);
        
        xx = max(xx, l);
        if(xx <= r){
            mp[xx]++;
        }
    }
    ll last = l, cnt = 0;
    for(auto i: mp){
//        cout<<last<<' '<<i.first<<' '<<cnt<<endl;
        ll d = i.first-last;
        last = i.first;
        psa[cnt] += d;
        cnt += i.second;
    }
    cout<<psa[0]<<'\n';
    for(int i = 1; i <= n; i++){
        psa[i] += psa[i-1];
        cout<<psa[i]<<'\n';
    }
}
/*

3
-7 7 3
0 2 3
-4 2 1
3 3 1

1
-2 2 3
0 2 3
 
 */