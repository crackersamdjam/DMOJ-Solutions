#include <bits/stdc++.h>
using namespace std;
const int MM = 102;

int n, a[MM], dp[MM][MM][MM];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    memset(dp, 0x3f, sizeof dp);
    cin >> n >> a[1];
    dp[1][0][1] = (a[1] != 0);
    for(int i = 2; i <= n; i++){
        cin >> a[i];
        for(int j = 1; j <= i; j++){
            for(int k = 0; k <= i; k++){
                dp[i][j][k] = min(dp[i][j][k], dp[i-1][j-1][k] + (j != a[i]));
            }
        }
        for(int j = 0; j <= i; j++){
            for(int k = 1; k <= i; k++){
                dp[i][0][k] = min(dp[i][0][k], dp[i-1][j][k-1] + (0 != a[i]));
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        int ans = 1e9;
        for(int j = 0; j <= n; j++)
            ans = min(ans, dp[n][j][i]);
        cout << ans << '\n';
    }
    
    return 0;
}