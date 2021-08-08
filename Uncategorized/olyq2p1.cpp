#include <bits/stdc++.h>
#define MM 100002
using namespace std;
int arr[MM],N,M,ans=0;
bool memed;
int main(){
    scanf("%d%d",&N,&M);
    for(int i = 0; i < N; i++){
        scanf("%d",arr+i);
    }
    sort(arr,arr+N);
    int l = 0,m,r = arr[N-1];
    while(l <= r){
        m = (l+r)/2;
        memed = 0;
        int rem = M-1, pre = arr[0];
        for(int i = 1; i < N; i++){
            if(arr[i] - pre >= m){
                pre = arr[i];
                rem--;
                if(rem == 0){
                    memed = 1;
                    break;
                }
            }
        }
        if(memed){
            ans = max(ans, m);
            l = m+1;
        }else
            r = m-1;
    }
    printf("%d\n",ans);
    return 0;
}