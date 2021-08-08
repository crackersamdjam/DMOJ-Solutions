#include <bits/stdc++.h>
using namespace std;
int dp[102][102];
int main() {
    memset(dp, 0, sizeof(dp));
    int n; scanf("%d",&n);
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < i; j++)
            scanf("%d",&dp[i][j]);
    for(int i = n; i >= 1; i--)
        for(int j = i-1; j >= 0; j--)
            dp[i][j] += max(dp[i+1][j], dp[i+1][j+1]);
    printf("%d\n", dp[1][0]);
    return 0;
}