#include <bits/stdc++.h>
#define MM 252
using namespace std;
int dp[MM][MM][MM],N,K;
int f(int n,int k,int pre){
    if(dp[n][k][pre])
        return dp[n][k][pre];
    if(k == 1)
        return dp[n][k][pre] = 1;
    for(int i = pre; i <= n/k; i++){
        dp[n][k][pre] += f(n-i,k-1,i);
    }
    return dp[n][k][pre];
}
int main(){
    scanf("%d%d",&N,&K);
    printf("%d\n",f(N,K,1));
    return 0;
}