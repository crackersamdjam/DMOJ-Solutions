#include <bits/stdc++.h>
#define MM 1002
#define f first
#define s second
using namespace std;
int N,ans,at,ft,sd;
int arr[MM];
vector<int> one,two;
int main(){
    scanf("%d",&N);
    for(int i = 0,r; i < N; i++){
        scanf("%d",&r);
        arr[r]++;
    }
    for(int i = 0; i < MM; i++){
        if(arr[i] > ft){
            sd = ft;
            ft = arr[i];
        }else if(arr[i] > sd){
            sd = arr[i];
        }
    }
    for(int i = 0; i < MM; i++){
        if(arr[i] == ft)
            one.push_back(i);
        else if(arr[i] == sd)
            two.push_back(i);
    }
    for(auto i: one){
        for(auto j: one)
            ans = max(ans,abs(i-j));
        for(auto j: two)
            ans = max(ans,abs(i-j));
    }
    printf("%d\n",ans);
    return 0;
}