#include <bits/stdc++.h>
#define MM 1002
using namespace std;
int arr[MM], N, T, best;
int main(){
    scanf("%d%d",&N,&T);
    for(int i = 0; i < N; i++){
        scanf("%d",arr+i);
    }
    arr[N] = 0;
    sort(arr,arr+N+1);
    best = INT_MAX;
    for(int i = 0; i <= N-T; i++){
        int j = i+T;
        if(arr[i] > 0 || arr[j] < 0)
            continue;
        best = min(best, min(-arr[i],arr[j])*2 + max(-arr[i],arr[j]));
    }
    printf("%d\n", best);
    return 0;
}
/*
 * left distance travelled, right distance travelled
 * max + min*2
 * sliding window
 *
 * j - i + 1 - 1 = T
 *         (added 0)
 */