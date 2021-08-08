#include <bits/stdc++.h>
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
int N, a[700], sum, half;
bool dp[700*700*2];
int main(){
    sc(N);
    for(int i = 0; i < N; i++){
        sc(a[i]);
        sum += a[i];
    }
    half = sum/2;
    dp[0] = 1;
    for(int i = 0; i < N; i++){
        for(int j = half; j >= a[i]; j--){
            if(dp[j-a[i]])
                dp[j] = 1;
        }
    }
    for(int i = half; i >= 0; i--){
        if(dp[i]){
            printf("%d\n", sum - 2*i);
            return 0;
        }
    }
    return 0;
}