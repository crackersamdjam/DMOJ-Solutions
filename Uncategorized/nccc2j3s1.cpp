#include <bits/stdc++.h>
#define MM 51
using namespace std;
typedef long long ll;
int N,h;
ll sum = 0;
int main(){
    scanf("%d",&N);
    for(int i = 0,n; i < N; i++){
        scanf("%d",&n);
        h = max(h,n);
        sum += n;
    }
    printf("%lld\n", sum-max((ll)h,(sum+1)/2));
    return 0;
}