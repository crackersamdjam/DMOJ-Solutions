#include <bits/stdc++.h>
using namespace std;
#define MM 26
int dp[MM][MM];
bool cat[MM][MM];
int main() {
    memset(dp,0, sizeof(dp));
    int r, c; scanf("%d%d",&r,&c);
    int k; scanf("%d",&k);
    for(int i = 0,x,y; i < k; i++){
        scanf("%d%d",&x,&y);
        cat[x][y] = true;
    }
    dp[0][1] = 1;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            if(!cat[i][j]){
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
    }
    printf("%d\n",dp[r][c]);
    return 0;
}