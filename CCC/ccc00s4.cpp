#include <bits/stdc++.h>
using namespace std;
int c[32], dp[5283];
int main() {
    int d, n; scanf("%d%d",&d,&n);
    for(int i = 0; i < n; i++)
        scanf("%d",&c[i]);
    memset(dp,0x3f,sizeof(dp));
    dp[0] = 0;
    for(int i = 1; i <= d; i++){ // at dis
        for(int j = 0; j < n; j++){ //clubs
            if(i-c[j] >= 0){
                dp[i] = min(dp[i], dp[i-c[j]] + 1);
            }
            //printf("%d %d\n",i,dp[i]);
        }
    }
    dp[d] == 0x3f3f3f3f?
    printf("Roberta acknowledges defeat.\n"):
    printf("Roberta wins in %d strokes.\n",dp[d]);
    return 0;
}