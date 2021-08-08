#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MM = 1e4+2;

char k[MM];
ll dp[MM][100][2], mod = 1e9+7;
int d, n;

ll m(ll x){
    return ((x%d)+d)%d;
}

ll go(int i, int s, int b){
    if(i == n+1){
        return !s;
    }
    if(~dp[i][s][b])
        return dp[i][s][b];
    ll cur = 0;
    if(b){
        for(int j = 0; j < k[i]-'0'; j++){
            cur += go(i+1, m(s-j), 0);
            cur %= mod;
        }
        cur += go(i+1, m(s-k[i]+'0'), 1);
        cur %= mod;
    }
    else{
        for(int j = 0; j < 10; j++){
            cur += go(i+1, m(s-j), 0);
            cur %= mod;
        }
    }
    return dp[i][s][b] = cur;
}

int main(){
    memset(dp, -1, sizeof dp);
    scanf("%s %d", k+1, &d);
    n = strlen(k+1);
    cout << go(1, 0, 1)-1 << '\n';
    
    return 0;
}