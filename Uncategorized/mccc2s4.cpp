#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MM = 1e5+2;

int n, a[MM];
ll ans = 1e16;

void run(int k){
    //k is group size
    ll val = 0;
    for(int s = 0; s < k; s++){
        ll a1 = 0, a2 = 0;
        //this group
        vector<int> v;
        for(int j = s; j < n; j += k)
            v.emplace_back(a[j]);
        sort(v.begin(), v.end());
        int m1 = v[v.size()/2], m2 = v[(v.size()-1)/2];
        for(int j = s; j < n; j += k){
            a1 += abs(a[j]-m1);
            a2 += abs(a[j]-m2);
        }
        val += min(a1, a2);
    }
    ans = min(ans, val);
}

int main(){
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>a[i];
    run(1);
    for(int i = 1; i < n; i++)
        if(n%i == 0)
            run(i);
    
    cout<<ans<<'\n';
    
    return 0;
}