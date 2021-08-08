#include <bits/stdc++.h>
using namespace std;
#define MM 102
int dp[MM][MM][3],arr[MM][MM];
//moved up, down, right
char c;
int main(){
    while(1){
        int m,n;
        scanf("%d%d",&m,&n);
        if(m == 0)
            break;
        for(int i = m; i > 0; i--){
            scanf("%c",&c); //nl
            for(int j = 1; j <= n; j++){
                scanf("%c",&c);
                if(c == '*'){
                    arr[i][j] = -1;
                }else if(c == '.'){
                    arr[i][j] = 0;
                }else{
                    arr[i][j] = c-'0';
                }
                //printf("%d ",arr[i][j]);
            }
            //printf("\n");
        }
        memset(dp,-1,sizeof(dp));
        dp[1][1][2] = max(0, arr[1][1]);
        for(int j = 1; j <= n; j++){
            for(int i = m; i > 0; i--){
                if(arr[i][j] == -1)
                    continue;
                if(dp[i][j-1][2] != -1)
                    dp[i][j][2] = max(dp[i][j][2], dp[i][j-1][2] + arr[i][j]);
                if(dp[i][j-1][1] != -1)
                    dp[i][j][2] = max(dp[i][j][2], dp[i][j-1][1] + arr[i][j]);
                if(dp[i][j-1][0] != -1)
                    dp[i][j][2] = max(dp[i][j][2], dp[i][j-1][0] + arr[i][j]);

                //down
                if(dp[i-1][j][1] != -1)
                    dp[i][j][1] = max(dp[i][j][1], dp[i-1][j][1] + arr[i][j]);
                if(dp[i-1][j][2] != -1)
                    dp[i][j][1] = max(dp[i][j][1], dp[i-1][j][2] + arr[i][j]);

                //up
                if(dp[i+1][j][0] != -1)
                    dp[i][j][0] = max(dp[i][j][0], dp[i+1][j][0] + arr[i][j]);
                if(dp[i+1][j][2] != -1)
                    dp[i][j][0] = max(dp[i][j][0], dp[i+1][j][2] + arr[i][j]);
            }
            for(int i = 1; i <= m; i++){
                if(arr[i][j] == -1)
                    continue;
                if(dp[i][j-1][2] != -1)
                    dp[i][j][2] = max(dp[i][j][2], dp[i][j-1][2] + arr[i][j]);
                if(dp[i][j-1][1] != -1)
                    dp[i][j][2] = max(dp[i][j][2], dp[i][j-1][1] + arr[i][j]);
                if(dp[i][j-1][0] != -1)
                    dp[i][j][2] = max(dp[i][j][2], dp[i][j-1][0] + arr[i][j]);

                //down
                if(dp[i-1][j][1] != -1)
                    dp[i][j][1] = max(dp[i][j][1], dp[i-1][j][1] + arr[i][j]);
                if(dp[i-1][j][2] != -1)
                    dp[i][j][1] = max(dp[i][j][1], dp[i-1][j][2] + arr[i][j]);

                //up
                if(dp[i+1][j][0] != -1)
                    dp[i][j][0] = max(dp[i][j][0], dp[i+1][j][0] + arr[i][j]);
                if(dp[i+1][j][2] != -1)
                    dp[i][j][0] = max(dp[i][j][0], dp[i+1][j][2] + arr[i][j]);
            }
        }
        printf("%d\n",max(max(dp[1][n][0],dp[1][n][1]),dp[1][n][2]));
#ifdef def
        for(int i = m; i > 0; i--){
            for(int j = 1; j <= n; j++){
                printf("%d ",max(max(dp[i][j][0],dp[i][j][1]),dp[i][j][2]));
            }
            printf("\n");
        }
#endif
    }
    return 0;
}