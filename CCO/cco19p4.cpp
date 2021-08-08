#include <bits/stdc++.h>
using namespace std;
typedef double ld;
constexpr int MM = 1e6+1;

int n, best[MM];
ld dp[MM], p[MM], k;
vector<int> v[MM];

void thing(int j, int i, int t){
    ld val = dp[v[t][j]-1] + p[v[t].size()-j];
    if(val > dp[i]){
        dp[i] = val;
        best[t] = j;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>k>>n;
    k /= 2.0;
    
    for(int i = 1,a; i <= n; i++){
        p[i] = pow(i, k);
        cin>>a;
        v[a].emplace_back(i);
        
        int l = max(0, best[a]-100), r = min((int)v[a].size(), best[a]+100);
        
        for(int j = l; j < r; j++)
            thing(j, i, a);
        
        for(int j = 0; j < min(l, 100); j++)
            thing(j, i, a);
        
        for(int j = max(r, (int)v[a].size() - 100); j < (int)v[a].size(); j++)
             thing(j, i, a);
    }
    cout<<fixed<<setprecision(10)<<dp[n];
}