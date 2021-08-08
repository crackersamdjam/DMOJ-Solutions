#include <bits/stdc++.h>
#define MM 1000002
using namespace std;
typedef long long ll;
ll a[MM],ai,ans;
int N;
int main(){
    scanf("%d",&N);
    for(int i = 3; i < N+3; i++){
        scanf("%lld",&ai);
        a[i] = max(a[i-2]+ai,a[i-1]);
        ans = max(ans, a[i]);
    }
    printf("%lld\n", ans);
    return 0;
}