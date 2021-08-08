#include <bits/stdc++.h>
#define MM 100000
using namespace std;
int a[MM+3],T,K,A,B;
vector<int> arr[320];
int main(){

    a[1] = 1;
    for(int i = 2; i <= MM; i++){
        a[i]++;
        for(int j = i; j <= MM; j += i){
            a[j]++;
        }
    }

    for(int i = 1; i <= MM; i++)
        arr[a[i]].push_back(i);

    for(int i = 1; i < 320; i++)
        sort(arr[i].begin(),arr[i].end());

    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&K,&A,&B);
        if(K > 320){
            printf("0\n");
            continue;
        }
        printf("%d\n", (int)(upper_bound(arr[K].begin(), arr[K].end(), B) -
        lower_bound(arr[K].begin(), arr[K].end(), A)));
    }
    return 0;
}