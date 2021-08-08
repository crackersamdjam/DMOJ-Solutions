#include <bits/stdc++.h>
#define MM 5002
using namespace std;
int N,k,dp[2][MM];
char str[MM];
int main(){
    scanf("%d%s",&N,str);
    for(int i = 0; i < N; i++){
        k ^= 1;
        for(int j = 0; j < N; j++){
            if(str[i] == str[N-1-j]){
                dp[k][j] = dp[k^1][j-1] + 1;
            }else{
                dp[k][j] = max(dp[k^1][j], dp[k][j-1]);
            }
        }
    }
    printf("%d\n",N-dp[k][N-1]);
    return 0;
}