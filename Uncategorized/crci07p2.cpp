#include <bits/stdc++.h>
#define MM 1002
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
int dp[MM][MM], a[MM], N;
int go(int n, int k){
    if(n == N-1)
        return a[N-1];
    if(n < 0 || n >= N)
        return 0x3f3f3f3f;
    if(dp[n][k])
        return dp[n][k];
    return dp[n][k] = a[n] + min(go(n-k,k), go(n+k+1,k+1));
}
int main(){
    sc(N);
    for(int i = 0; i < N; i++)
        sc(a[i]);
    printf("%d\n", go(1,1));
    return 0;
}