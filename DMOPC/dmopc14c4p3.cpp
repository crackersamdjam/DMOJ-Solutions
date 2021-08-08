#include <bits/stdc++.h>
using namespace std;
#define MM 1005
int arr[MM][MM], dp[MM][MM];
int main() {
    memset(dp,0x3f,sizeof(dp));
    int l, d; scanf("%d%d",&l,&d);
    for(int i = 0; i < d; i++)
        for(int j = 0; j < l; j++)
            scanf("%d",&arr[i][j]);
    int a, b; scanf("%d%d",&a,&b);
    dp[0][0] = arr[0][0];
    for(int x = 1; x < l; x++)
        dp[0][x] = dp[0][x-1] + arr[0][x];
    for(int y = 1; y < d; y++){
        dp[y][0] = dp[y-1][0] + arr[y][0];
        for(int x = 1; x < l; x++)
            dp[y][x] = min(dp[y-1][x], dp[y][x-1]) + arr[y][x];
        for(int x = l-2; x >= 0; x--)
            dp[y][x] = min(dp[y][x], dp[y][x+1] + arr[y][x]);
    }
    printf("%d\n",dp[b][a]);
    return 0;
}