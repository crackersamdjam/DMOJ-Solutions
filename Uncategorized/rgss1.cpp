#include <bits/stdc++.h>
#define MM 1002
using namespace std;
int A,B,C,ans;
bool dp[MM];
int main(){
    scanf("%d%d%d",&A,&B,&C);
    dp[0] = 1;
    for(int i = 0; i <= C; i++){
        if(dp[i]){
            dp[i+A] = dp[i+B] = 1;
            ans = i;
        }
    }
    printf("%d\n",ans);
    return 0;
}