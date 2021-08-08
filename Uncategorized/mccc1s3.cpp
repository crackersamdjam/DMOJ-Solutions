#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MM = 4e5+5;

ll base = 131, mod = 1685518853, base2 = 31, mod2 = 1e9+9;

string s;
ll a[MM], a2[MM], h[MM], h2[MM];
int q, t;
map<pair<ll, ll>, int> mp;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s>>q;
    ll hs = 0, hs2 = 0;
    for(char c: s){
        hs = (hs*base+c)%mod;
        hs2 = (hs2*base2+c)%mod2;
        mp[{hs, hs2}] = 1;
    }
    a[++t] = hs;
    a2[t] = hs2;
    
    while(q--){
        char op; int i; char cc;
        cin>>op;
        if(op == 'C'){
            cin>>i>>cc;
            hs = (a[i]*base+cc)%mod;
            hs2 = (a2[i]*base2+cc)%mod2;
            a[++t] = hs;
            a2[t] = hs2;
            if(!mp.count({hs, hs2})) //earliest string #
                mp[{hs, hs2}] = t;
        }
        else{
            cin>>s;
            for(i = 1; i <= s.size(); i++)
                h[i] = (h[i-1]*base+s[i-1])%mod;
            for(i = 1; i <= s.size(); i++)
                h2[i] = (h2[i-1]*base2+s[i-1])%mod2;
            for(i = s.size(); i; i--){
                if(mp.count({h[i], h2[i]})){
                    cout<<mp[{h[i], h2[i]}]<<'\n';
                    goto out;
                }
            }
            cout<<"-1\n";
            out:;
        }
    }
    
    return 0;
}