#include <bits/stdc++.h>
using namespace std;
int arr[6],high=0,ans;
int main(){
    for(int i = 1; i <= 5; i++){
        for(int j = 0,temp; j < 4; j++){
            scanf("%d",&temp);
            arr[i] += temp;
        }
        if(arr[i] > high){
            high = arr[i];
            ans = i;
        }
    }
    printf("%d %d\n",ans,arr[ans]);
    return 0;
}