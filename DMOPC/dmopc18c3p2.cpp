#include <bits/stdc++.h>
#define MM 100002
#define sc(x) scanf("%d",&x);
char _;
using namespace std;
int N,dp[MM][3],a[MM],b[MM];
int main(){
    sc(N);
    for(int i = 1; i <= N; i++)
        sc(a[i]);
    for(int i = 1; i <= N; i++)
        sc(b[i]);
    for(int i = 1; i <= N; i++){
        dp[i][0] = INT_MIN;
        for(int j = 0; j < 3; j++)
            dp[i][0] = max(dp[i][0], dp[i-1][j] + b[i]);
        for(int j = 1; j < 3; j++)
            dp[i][j] = dp[i-1][j-1] + a[i];
    }
    int ans = INT_MIN;
    for(int i = 0; i < 3; i++)
        ans = max(ans, dp[N][i]);
    printf("%d\n", ans);
    return 0;
}