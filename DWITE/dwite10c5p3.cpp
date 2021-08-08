#include <bits/stdc++.h>
#define MM 1002
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
int a[MM], N, T = 5, ans, high;
void go(int n, int num){
    if(n == N){
        ans = min(ans, abs(num));
    }else{
        if(num <= high+1000)
            go(n+1, num+a[n]);
        if(num >= -high-1000)
            go(n+1, num-a[n]);
    }
}
int main(){
    while(T--){
        sc(N);
        for(int i = 0; i < N; i++){
            sc(a[i]);
            high = max(high, a[i]);
        }
        ans = INT_MAX;
        go(0, 0);
        printf("%d\n", ans);
    }
    return 0;
}