#include <bits/stdc++.h>
using namespace std;
#define MM 258
int N,sum,dp[MM][MM];
char nl;
int main(){
    for(int tc = 0; tc < 5; tc++){
        scanf("%d",&N);
        sum = 0;
        for(int i = 1; i <= N; i++){
            scanf("%c",&nl);
            for(int j = 1; j <= N; j++){
                scanf("%c",&nl);
                dp[i][j] = (nl == '#');
            }
        }
        for(int i = N-1; i > 0; i--)
            for(int j = 1; j <= N; j++)
                if(dp[i][j] && dp[i+1][j-1] && dp[i+1][j] && dp[i+1][j+1])
                    dp[i][j] += min(dp[i+1][j-1], min(dp[i+1][j], dp[i+1][j+1]));

        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                sum += dp[i][j];

        printf("%d\n", sum);
    }
    return 0;
}