#include <bits/stdc++.h>
using namespace std;
#define MM 20002
int arr[202], num[202], dp[202][MM];
int main() {
    int n; scanf("%d",&n);
    for(int i = 1; i <= n; i++)
        scanf("%d",&arr[i]);
    for(int i = 1; i <= n; i++)
        scanf("%d",&num[i]);
    int K; scanf("%d",&K);
    memset(dp,0x3f,sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= K; j++){
            for(int k = 0; k <= num[i] && k*arr[i] <= j; k++){
                dp[i][j] = min(dp[i][j],dp[i-1][j-arr[i]*k]+k);
            }
            //printf("%d ",dp[i][j]);
        }
        //printf("\n");
    }
    printf("%d\n",dp[n][K]);
    return 0;
}