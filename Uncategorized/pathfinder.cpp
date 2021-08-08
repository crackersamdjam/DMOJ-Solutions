#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;

int n, m, k, par[MM], ls[MM], rs[MM];

int find(int x){
    while(x != par[x])
        x = par[x], par[x] = par[par[x]];
    return x;
}

void merge(int a, int b){
    a = find(a), b = find(b);
    par[b] = a;
    ls[a] |= ls[b];
    rs[a] |= rs[b];
    if(ls[a] and rs[a]){
        cout<<"NO\n";
        exit(0);
    }
}

map<pair<int, int>, int> mp;
vector<int> mx = {1, 1, 1, 0, 0, -1, -1, -1}, my = {1, 0, -1, 1, -1, 1, 0, -1};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for(int i = 1,a,b; i <= k; i++){
        par[i] = i;
        cin>>a>>b;
        if(b == 1 or a == n)
            rs[i] = 1;
        if(a == 1 or b == m)
            ls[i] = 1;

        for(int l = 0; l < 8; l++){
            int c = a+mx[l], d = b+my[l];
            if(mp.count({c, d})){
                merge(mp[{c, d}], i);
            }
        }
        mp[{a, b}] = i;
    }
    cout<<"YES\n";
    return 0;
}