#include <bits/stdc++.h>
#define MM 1000002
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
typedef long long ll;
int N,K,a[MM],pre[MM],nx[MM];
ll b[MM],dp[MM][2];
ll go(int n, bool bl){
    if(n > N)
        return 0;
    if(dp[n][bl] != -1)
        return dp[n][bl];
    dp[n][bl] = go(n+1,0) + (bl? (b[n] - b[n-1]): 0);
    if(nx[n]){
        dp[n][bl] = max(dp[n][bl], go(nx[n], 1) + b[nx[n] - 1] - b[n - 1]);
    }
    return dp[n][bl];
}
int main(){
    memset(dp,-1,sizeof dp);
    sc(N); sc(K);
    for(int i = 1; i <= N; i++){
        sc(a[i]);
        if(pre[a[i]]){
            nx[pre[a[i]]] = i;
        }
        pre[a[i]] = i;
    }
    for(int i = 1; i <= N; i++){
        sc(b[i]);
        b[i] += b[i-1];
    }
    printf("%lld\n", go(1, 0));
    return 0;
}