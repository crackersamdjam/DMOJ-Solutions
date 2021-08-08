#include <bits/stdc++.h>
#define MM 5002
typedef long long ll;
ll dp[MM];
int cost[MM],val[MM],N;
inline ll min(ll a, ll b){
    return (a < b) ? a : b;
}
int main(){
    memset(dp,0x3f,sizeof(dp));
    dp[0] = 0;
    scanf("%d",&N);
    for(int i = 0; i < N; i++){
        scanf("%d%d",cost+i,val+i);
        for(int j = N; j >= i; j--){
            if(j + val[i] < N)
                dp[j+val[i]] = min(dp[j+val[i]], dp[j] + cost[i]);
            else
                dp[N-1] = min(dp[N-1], dp[j] + cost[i]);
        }
    }
    printf("%lld\n",dp[N-1]);
    return 0;
}