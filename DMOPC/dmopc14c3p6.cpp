#include <bits/stdc++.h>
using namespace std;
#define MM 2002
int dp[2][10002];
int cost[MM][3], val[MM][3];
int main(){
    int n, t; scanf("%d%d",&n,&t);
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < 3; j++)
            scanf("%d%d",&cost[i][j],&val[i][j]);
    for(int i = 0; i <= n; i++){
        int aci = i%2, pre; aci == 0? pre = 1: pre = 0;
        for(int j = 0; j <= t; j++){
            if(i==0||j==0) dp[aci][j] = 0;
            else
                for(int k = 0; k < 3; k++) {
                    if(cost[i][k] > j)
                        dp[aci][j] = max(dp[aci][j],dp[pre][j]);
                    else
                        dp[aci][j] = max(dp[aci][j], max(dp[pre][j], dp[pre][j-cost[i][k]] + val[i][k]));
                }
        }
    }
    printf("%d\n", dp[n%2][t]);
    return 0;
}