#include <bits/stdc++.h>
#define MM 2002
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
pii arr[MM];
int dp[2][MM][MM],psa[MM],N,st,ans;
inline pii go(int l, int r){
    if(l < 0 || r >= N || l > r || (l != st && l == r))
        return {INT_MIN,INT_MIN};
    if(dp[0][l][r] != -1)
        return {dp[0][l][r],dp[1][l][r]};
    dp[0][l][r] = dp[1][l][r] = 0;
    int dif = arr[l+1].f - arr[l].f;
    if(go(l+1,r).f >= dif){
        dp[0][l][r] = max(dp[0][l][r], go(l+1,r).f - dif + arr[l].s);
    }
    dif = arr[r].f - arr[l].f;
    if(go(l+1,r).s >= dif){
        dp[0][l][r] = max(dp[0][l][r], go(l+1,r).s - dif + arr[l].s);
    }
    dif = arr[r].f - arr[r-1].f;
    if(go(l,r-1).s >= dif){
        dp[1][l][r] = max(dp[1][l][r], go(l,r-1).s - dif + arr[r].s);
    }
    dif = arr[r].f - arr[l].f;
    if(go(l,r-1).f >= dif){
        dp[1][l][r] = max(dp[1][l][r], go(l,r-1).f - dif + arr[r].s);
    }
    if(dp[0][l][r] > 0)
        ans = max(ans, psa[r] - (l-1 < 0 ? 0 : psa[l-1]));
    if(dp[1][l][r] > 0)
        ans = max(ans, psa[r] - (l-1 < 0 ? 0 : psa[l-1]));
    return {dp[0][l][r],dp[1][l][r]};
}
int main(){
    memset(dp,-1,sizeof(dp));
    scanf("%d",&N);
    for(int i = 0; i < N; i++)
        scanf("%d%d",&arr[i].f,&arr[i].s);
    sort(arr,arr+N);
    psa[0] = arr[0].s;
    dp[0][0][0] = dp[1][0][0] = 0;
    for(int i = 1; i < N; i++){
        psa[i] = arr[i].s + psa[i-1];
        dp[0][i][i] = dp[1][i][i] = 0;
    }
    for(st = 0; arr[st].f != 0; st++);
    ans = dp[0][st][st] = dp[1][st][st] = arr[st].s;
    go(0,N-1);
    printf("%d\n",ans);
    return 0;
}