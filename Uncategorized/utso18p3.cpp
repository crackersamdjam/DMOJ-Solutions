#include <bits/stdc++.h>
#define MM 1000002
using namespace std;
bool arr[MM];
int N,T,K,V,a, cnt = 0, ans = 0;
int main(){
    scanf("%d%d%d%d",&N,&T,&K,&V);
    while(V--){
        scanf("%d",&a);
        arr[a] = 1;
        if(a <= T)
            cnt++;
    }
    for(int i = T; i > 0 && cnt < K; i--){
        if(!arr[i]){
            arr[i] = 1;
            cnt++;
            ans++;
        }
    }
    for(int i = T+1; i <= N; i++){
        if(arr[i-T])
            cnt--;
        if(arr[i])
            cnt++;
        if(cnt < K){
            arr[i] = 1;
            cnt++;
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}