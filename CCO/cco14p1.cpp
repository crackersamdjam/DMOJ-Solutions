#include <bits/stdc++.h>
using namespace std;
#define MM 2002
int dp[MM][MM];
int main() {
    int n; scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        char nl; scanf("%c",&nl);
        for(int j = 1; j <= n; j++) {
            char in; scanf("%c", &in);
            dp[i][j] = (in == '#');
        }
    }
    for(int i = n-1; i > 0; i--)
        for(int j = 1; j < n; j++)
            if(dp[i][j] && dp[i+1][j-1] && dp[i+1][j] && dp[i+1][j+1])
                dp[i][j] += min(dp[i+1][j-1],min(dp[i+1][j],dp[i+1][j+1]));
    int sum = 0;
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            sum+=dp[i][j];
    printf("%d\n",sum);
    return 0;
}