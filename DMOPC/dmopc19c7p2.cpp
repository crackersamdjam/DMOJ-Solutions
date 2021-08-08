#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;

int n, sum;
pair<int, int> a[MM], b[MM];

void go(int t){
    for(int i = 0; i < n; i++)
        a[i] = b[i];
    vector<pair<pair<int, int>, int>> v;
    a[0].first -= t;
    a[n-1].first -= t;
    v.push_back({{a[n-1].second, a[0].second}, t});

    for(int i = 1; i < n; i++){
        v.push_back({{a[i-1].second, a[i].second}, a[i-1].first});
        a[i].first -= a[i-1].first;
        a[i-1].first = 0;
        if(a[i].first < 0)
            return;
    }
    if(a[n-1].first)
        return;

    cout<<"YES\n"<<sum/2<<'\n';
    for(auto i: v)
        while(i.second--)
            cout<<i.first.first<<' '<<i.first.second<<'\n';
    exit(0);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a[i].first;
        a[i].second = i;
        sum += a[i].first;
    }
    auto p = min_element(a, a+n);
    rotate(a, p, a+n);

    assert(a == min_element(a, a+n));;

    for(int i = 0; i < n; i++)
        b[i] = a[i];
    for(int i = 0; i <= b[0].first; i++){
        go(i);
    }

    cout<<"NO\n";

    return 0;
}