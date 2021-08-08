#include <bits/stdc++.h>
#define MM 1000002
using namespace std;
int arr[MM],N,T,L,a,b,c,ans,sum,l,r;
int main(){
    scanf("%d%d",&N,&T);
    while(T--){
        scanf("%d%d%d",&a,&b,&c);
        arr[a] += c;
        arr[b+1] -= c;
    }
    for(int i = 2; i <= N; i++)
        arr[i] += arr[i-1];

    scanf("%d",&L);
    l = r = 1;
    sum = arr[1];
    while(l <= r && r <= N){
        if(sum <= L){
            ans = max(ans,r-l+1);
            sum += arr[++r];
        }else
            sum -= arr[l++];
    }
    printf("%d\n",ans);
    return 0;
}