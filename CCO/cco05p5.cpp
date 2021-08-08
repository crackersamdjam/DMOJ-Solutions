#include <bits/stdc++.h>
#define MM 20002
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
int dp[MM][2],N,val;
//cost to get there, 0:1 find arr[i] first : second
pii arr[MM];
int main(){
    scanf("%d",&N);
    for(int i = 1; i <= N; i++){
        scanf("%d%d",&arr[i].f,&arr[i].s);
    }
    memset(dp,0x3f,sizeof(dp));
    arr[0] = {1,1};
    dp[0][0] = dp[0][1] = 0;
    for(int i = 1; i <= N; i++){
        dp[i][0] = dp[i-1][0] + abs(arr[i-1].f - arr[i].s)
                      + abs(arr[i].s - arr[i].f);

        val = dp[i-1][1] + abs(arr[i-1].s - arr[i].s)
                           + abs(arr[i].s - arr[i].f);
        dp[i][0] = min(dp[i][0],val);

        dp[i][1] = dp[i-1][0] + (abs(arr[i-1].f - arr[i].f)
                         + abs(arr[i].s - arr[i].f));

        val = dp[i-1][1] + (abs(arr[i-1].s - arr[i].f)
                    + abs(arr[i].s - arr[i].f));
        dp[i][1] = min(dp[i][1],val);
    }
    printf("%d\n", N-1 + min(dp[N][0] + abs(N - arr[N].f),
                       dp[N][1] + abs(N - arr[N].s)));
#ifdef def
    for(int i = 1; i <= N; i++){
        printf("%d %d\n",dp[i][0],dp[i][1]);
    }
#endif
    return 0;
}
/*
 at every level, the choice is to go left or right
 each value stores the total cost from start
 including that current row
 (just before going down to next level)
 */