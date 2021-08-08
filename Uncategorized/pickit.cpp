#include <bits/stdc++.h>
#define MM 202
using namespace std;
int dp[MM][MM],arr[MM],N;
int go(int l, int r){
    if(dp[l][r] != -1)
        return dp[l][r];
    dp[l][r] = 0;
    for(int i = l+1; i < r; i++){
        dp[l][r] = max(dp[l][r],arr[l]+arr[i]+arr[r]+ go(l,i) + go(i,r));
    }
    return dp[l][r];
}
int main(){
    while(1){
        scanf("%d",&N);
        if(!N)
            break;
        for(int i = 0; i < N; i++)
            scanf("%d",arr+i);
        memset(dp,-1,sizeof(dp));
        printf("%d\n",go(0,N-1));
    }
    return 0;
}