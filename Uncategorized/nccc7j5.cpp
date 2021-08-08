#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MM = 1e7+1;

ll A, B, C, D;
int mu[MM];

ll go(int n, int m){
    ll cnt = 0;
    for(int i = 1; i <= max(n, m); i++){
        ll a = n/i, b = m/i;
        cnt += a*b*mu[i];
    }
    return cnt;
}

vector<int> p;
bool comp[MM];

int main(){
    
    mu[1] = 1;
    for(int i = 2; i < MM; i++){
        if(!comp[i]){
            p.emplace_back(i);
            mu[i] = -1;
        }
        for(int j: p){
            int k = i*j;
            if(k > MM)
                break;
            
            assert(!comp[k]);
            comp[k] = 1;
            //k only gets marked once
            mu[k] = mu[i] * mu[j]; //multiplicative
            
            if(i % j == 0){
                // j is prime, but i may not be. When j | i, k has >= 2 factors of j
                // k = p^2*d, so we don't want k
                mu[k] = 0;
                break;
            }
        }
//        cout<<i<<' '<<mu[i]<<'\n';
    }
    
    cin>>A>>B>>C>>D;
    A--, C--;
    cout << go(B, D) - go(A, D) - go(B, C) + go(A, C) << '\n';
    
    return 0;
}