#include <bits/stdc++.h>
using namespace std;
#define MM 1002
int dp[MM][MM];
int a[MM],b[MM];
int main() {
    int n, m; scanf("%d%d",&n,&m);
    for(int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    for(int i = 0; i < m; i++)
        scanf("%d",&b[i]);
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i==0 || j==0) dp[i][j] = 0;
            else if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    printf("%d\n",dp[n][m]);
    return 0;
}