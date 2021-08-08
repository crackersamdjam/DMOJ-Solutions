#include <bits/stdc++.h>
using namespace std;
int dp[152][302][102],M,U,R,v,t,f;
int main(){
    scanf("%d%d%d",&M,&U,&R); //m minutes, u units of food, r restaurants
    for(int i = 1; i <= R; i++){
        scanf("%d%d%d",&v,&t,&f);
        for(int j = 1; j <= M; j++){
            for(int k = 1; k <= U; k++){
                if(j-t >= 0 && k-f >= 0)
                    dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-t][k-f] + v);
                else
                    dp[i][j][k] = dp[i-1][j][k];
            }
        }
    }
    printf("%d\n",dp[R][M][U]);
    return 0;
}