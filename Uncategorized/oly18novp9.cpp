//roger number
#include <bits/stdc++.h>
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
typedef long long ll;
ll N, dp[12][12][2], d[12], L, R;
ll go(int pos, int pre, bool l){
    if(pos < 0)
        return 1;
    if(dp[pos][pre][l] != -1)
        return dp[pos][pre][l];
    
    int up = (l? d[pos]: 9), ret = 0;
    for(int i = 0; i <= up; i++){
        if(abs(i-pre) >= 2){
            ret += go(pos-1, i, l && (i == d[pos]));
        }
    }
    return dp[pos][pre][l] = ret;
}
inline ll solve(ll x){
    int n = 0;
    for(; x; x/=10)
        d[n++] = x%10;
    ll cnt = 0; //count single digits
    for(int i = 0; i < n; i++){
        int up = (i == n-1)? d[n-1]: 9;
        for(int j = 1; j <= up; j++){
            cnt += go(i-1, j, (i == n-1) && (j == d[n-1]));
            //different starting number
        }
    }
    return cnt;
}
int main(){
    memset(dp, -1, sizeof(dp));
    sc(L); sc(R);
    printf("%lld\n", solve(R) - solve(L-1));
    return 0;
}