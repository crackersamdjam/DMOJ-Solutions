#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int N,K,a[1002];
ll dp[1002][1002];
ll f(int n, int k){
  if (n>=0 && k==0)return 1;
  if (n<0 || k<0)return 0;
  if (dp[n][k]!=-1)return dp[n][k];
  return dp[n][k]=(f(n-1,k)+a[n]*f(n-1,k-1))% 998244353;
}
int main(){
    memset(dp,-1,sizeof(dp));
    scanf("%d %d",&N,&K);
    for (int i=1,x;i<=N;i++){
        scanf("%d",&x);
        a[x]++;
    }
    ll ans=f(N,K);
    printf("%llu\n",ans%998244353);
}