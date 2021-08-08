#include <bits/stdc++.h>
#define MM 200002
using namespace std;
typedef long long ll;
int arr[MM],M,N,K;
ll sum = 0;
int main(){
    scanf("%d%d%d",&M,&N,&K);
    for(int i = 0; i < K; i++)
        scanf("%d",arr+i);
    sort(arr,arr+K,greater<>());
    auto col = ceil((double)K/M);
    int ptr = col;
    for(int i = 0; i < col; i++){
        for(int j = 1; j < M && ptr < K; j++){
            sum += arr[i] - arr[ptr++] + j;
        }
    }
    printf("%lld\n", sum);
}