#include <bits/stdc++.h>
using namespace std;
#define MM 1002
int val[MM],cost[MM];
int dp[MM][MM];
int main() {
    memset(dp,0,sizeof(dp));
    int c,m; scanf("%d%d",&c,&m);
    for(int i = 0; i < c; i++)
        scanf("%d%d",&val[i],&cost[i]);
    for(int i = 0; i <= c; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(cost[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-cost[i-1]] + val[i-1]);
            }
        }
    }
    printf("%d\n",dp[c][m]);
    return 0;
}