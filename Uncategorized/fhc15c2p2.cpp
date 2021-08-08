#include <bits/stdc++.h>
using namespace std;

void init(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
    #endif
}

int t, bi[21][21];
double p, dp[21], pw[21];

int main(){
    init();
    cin>>t;
    bi[0][0] = 1;
    for(int i = 1; i < 21; i++)
        for(int j = 0; j < 21; j++)
            bi[i][j] = bi[i-1][j] + (j ? bi[i-1][j-1] : 0);
    for(int tc = 1; tc <= t; tc++){
        cin>>p;
        pw[0] = 1;
        for(int i = 1; i < 21; i++){
            dp[i] = 1;
            for(int j = 1; j <= i; j++){
                dp[i] += dp[i-j]*bi[i][j]*pow(p, j)*pow(1-p, i-j);
                //cout<<i<<' '<<j<<' '<<dp[i-j]<<' '<<bi[i][j]<<' '<<pw[i]<<' '<<dp[i-j]*bi[i][j]*pw[i]<<'\n';
            }
            dp[i] /= 1-pow(1-p, i); //itself
            //cout<<pw[i]<<' '<<dp[i]<<'\n';
        }
        printf("Case #%d: %.5lf\n", tc, dp[20]);
    }

    
    return 0;
}