#include <bits/stdc++.h>
#define MM 150002
using namespace std;
int arr[3][MM], dp[3][MM], N, p[] = {0,1,2}, ans = INT_MAX;
int main(){
    scanf("%d", &N);
    for(int i = 0; i < 3; i++)
        for(int j = 1; j <= N; j++)
            scanf("%d", &arr[i][j]);
    do{
        int a = p[0], b = p[1], c = p[2];
        memset(dp, 0, sizeof dp);
        dp[b][1] = dp[c][2] = 0x3f3f3f3f;
        for(int i = 1; i <= N-2; i++){
            dp[a][i] = dp[a][i-1] + arr[a][i];
        }
        for(int i = 2; i <= N-1; i++){
            dp[b][i] = min(dp[b][i-1], dp[a][i-1]) + arr[b][i];
        }
        for(int i = 3; i <= N; i++){
            dp[c][i] = min(dp[c][i-1], dp[b][i-1]) + arr[c][i];
        }
        ans = min(ans, dp[c][N]);
    } while(next_permutation(p, p+3));
    printf("%d\n", ans);
    return 0;
}