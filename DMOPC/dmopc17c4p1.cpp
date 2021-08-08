#include <bits/stdc++.h>
#define MM 100002
int arr[MM],N,Q,x,y,b=0;
int main(){
    scanf("%d%d",&N,&Q);
    while(Q--){
        scanf("%d%d",&x,&y);
        arr[x]++;
        arr[y]--;
    }
    if(arr[0] > 0) b++;
    for(int i = 1; i < N; i++){
        arr[i] += arr[i-1];
        if(arr[i] > 0) b++;
    }
    printf("%d %d\n",N-b,b);
    return 0;
}