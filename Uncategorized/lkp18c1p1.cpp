#include <bits/stdc++.h>
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
int N, K, a[11], ans;
int main(){
    sc(N); sc(K);
    for(int i = 0; i < N; i++)
        sc(a[i]);
    for(int i = N-1; i >= 0; i--){
        while(a[i] <= K){
            K -= a[i];
            ans++;
        }
    }
    if(K)
        printf("-1\n");
    else
        printf("%d\n", ans);
    return 0;
}