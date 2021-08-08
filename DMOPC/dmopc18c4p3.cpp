#include <bits/stdc++.h>
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
const int MM = 200002;

int N, a[MM], b[MM], dp[2][MM];
int main(){
    sc(N);
    for(int i = 1; i <= N; i++)
        sc(a[i]);
    for(int i = 1; i <= N; i++)
        sc(b[i]);
    
    dp[1][0] = 1e8;
    for(int i = 1; i <= N; i++){
        dp[0][i] = min(dp[0][i-1] + b[i], dp[1][i-1] + a[i]);
        dp[1][i] = min(dp[1][i-1] + b[i], dp[0][i-1] + a[i]);
    }
    printf("%d\n", dp[N&1][N]);
    return 0;
}