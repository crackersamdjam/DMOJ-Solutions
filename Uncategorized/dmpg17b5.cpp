#include <bits/stdc++.h>
using namespace std;
#define MM 1000002
int arr[MM];
int main() {
    memset(arr, 0, sizeof(arr));
    int n;
    scanf("%d",&n);
    for(int i = 1,t,w; i <= n; i++){
        scanf("%d%d",&t,&w);
        arr[t] = max(arr[t], w);
    }
    int m = 0;
    for(int i = 1; i <= MM; i++){
        if(arr[i] < m) arr[i] = m;
        m = arr[i];
    }
    int q;
    scanf("%d",&q);
    for(int i = 0,T; i < q; i++){
        scanf("%d",&T);
        printf("%d\n",arr[T]);
    }
    return 0;
}