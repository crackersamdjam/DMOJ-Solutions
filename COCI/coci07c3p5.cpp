#include <bits/stdc++.h>
#define MM 17
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
typedef long long ll;
ll ans = LLONG_MAX, dp[MM][140][2][2];
int S, a[MM], b[MM], n;
char as[MM], bs[MM];
ll go(int pos, int sum, int l, int r, ll num){
    if(pos == n){
        if(sum == S){
            ans = min(ans, num);
            return 1;
        }
        return 0;
    }
    if(dp[pos][sum][l][r] != -1)
        return dp[pos][sum][l][r];
    ll ret = 0;
    for(int i = (l? a[pos]: 0); i <= (r? b[pos]: 9); i++)
        ret += go(pos+1, sum+i, l&&(i == a[pos]), r&&(i == b[pos]), num*10 + i);
    
    return dp[pos][sum][l][r] = ret;
}
int main(){
    memset(dp,-1,sizeof dp);
    scanf("%s%s%d",as,bs,&S);
    n = strlen(bs);
    for(int i = 0; i < n; i++)
        b[i] = bs[i] - '0';
    int dif = n - strlen(as);
    for(int i = 0; i < n-dif; i++)
        a[i+dif] = as[i] - '0';
    printf("%lld\n", go(0,0,1,1,0));
    printf("%lld\n", ans);
    return 0;
}