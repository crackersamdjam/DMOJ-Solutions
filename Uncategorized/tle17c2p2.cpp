#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MM 1000001
int arr[MM];
int K,u,N,f;
int main() {
    scan(K);
    while(K--){
        scan(u);
        arr[u] = 1;
    }
    for(int i = 1; i < MM; i++){
        arr[i] += arr[i-1];
    }
    scan(N);
    while(N--){
        scan(f);
        printf("%d\n",f-arr[f]);
    }
    return 0;
}