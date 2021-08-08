#include <bits/stdc++.h>
using namespace std;
#define MM 1002
int arr[MM], dp[MM];
int main() {
    int n; scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        dp[i] = arr[i];
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, dp[i]);
    printf("%d\n",ans);
    return 0;
}