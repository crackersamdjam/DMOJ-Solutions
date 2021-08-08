#include <bits/stdc++.h>
#define MM 100002
#define MN 1000000000
#define inf 0x3f3f3f3f
using namespace std;
int arr[MM],fr[MM],N,K,l=0,m,r=MN,cur,cnt;
int go(int cap){ //capacity
    cur = 0, cnt = 1;
    for(int i = 1; i < N; i++){
        if(fr[i]){
            if(arr[i] - cur > cap)
                return inf;
            cnt++;
            cur = arr[i];
        }else if(arr[i+1] - cur > cap){
            //if next stop is too far
            cnt++;
            cur = arr[i];
        }
    }
    if(arr[N] - cur > cap)
        return inf;
    return cnt;
}
int main(){
    scanf("%d%d",&N,&K);
    for(int i = 1; i <= N; i++)
        scanf("%d%d",arr+i,fr+i);
    while(l <= r){
        m = (l+r)/2;
        if(go(m) <= K)
            r = m-1;
        else
            l = m+1;
    }
    l > MN? printf("DEA Bust!\n"): printf("%d\n",l);
    return 0;
}