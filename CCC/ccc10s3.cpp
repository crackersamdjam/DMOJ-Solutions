#include <bits/stdc++.h>
#define MM 1002
using namespace std;
const int mod = 1000000;
int H,K,l,m,r,ans,arr[MM], st;
inline bool go(int k){
    int cur = st+1, last = arr[st] + k*2, cnt = 1;
    if(cur >= H){
        cur = 0;
        last -= mod;
    }
    while(cur != st){
        if(arr[cur] > last){
            last = arr[cur] + k*2;
            cnt++;
        }
        cur++;
        if(cur >= H){
            cur = 0;
            last -= mod;
        }
    }
    return (cnt <= K);
}
/*
6
0 156790 336070 410838 456789 700000
2


(from house 6 - 4 )/2
144581

(from house 4 - 3)/2
168035

ans of 168035


(from house 6-1)/2
150000

(from house 2-5)/2
149999

therefore ans should be
150000
 */
int main(){
    scanf("%d",&H);
    for(int i = 0; i < H; i++){
        scanf("%d",arr+i);
    }
    sort(arr,arr+H);
    //precompute largest distance
    //always start from st
    int dif = mod - arr[H-1] + arr[0];
    st = 0;
    for(int i = 1; i < H; i++){
        if(arr[i] - arr[i-1] > dif){
            dif = arr[i] - arr[i-1];
            st = i;
        }
    }
    scanf("%d",&K);
    l = 0, r = mod, ans = INT_MAX;
    while(l <= r){
        m = (l+r)/2;
        if(go(m)){
            ans = min(ans,m);
            r = m-1;
        }else{
            l = m+1;
        }
    }
    //try again my shifting one over
    if(--st == -1)
        st = H-1;
    l = 0, r = mod;
    while(l <= r){
        m = (l+r)/2;
        if(go(m)){
            ans = min(ans,m);
            r = m-1;
        }else{
            l = m+1;
        }
    }
    printf("%d\n",ans);
    return 0;
}