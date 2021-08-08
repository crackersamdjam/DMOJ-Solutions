#include <bits/stdc++.h>
using namespace std;
#define MM 1000002
int arr[MM], psa[MM];
int main() {
    int n; scanf("%d",&n);
    scanf("%d",&arr[0]); psa[0] = arr[0];
    for(int i = 1; i < n; i++){
        scanf("%d",&arr[i]);
        psa[i] = psa[i-1] + arr[i];
    }
    int q; scanf("%d",&q);
    for(int i = 0,a,b; i < q; i++){
        scanf("%d%d",&a,&b);
        printf("%d\n",psa[b]-psa[a]+arr[a]);
    }
    return 0;
}