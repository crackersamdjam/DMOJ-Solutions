#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
long long arr[200002];
int main() {
    int N,M; long long K;
    scan(N); scan(M); scan(K);
    if(K==0){
        printf("0\n");
        return 0;
    }
    arr[1] = M;
    for(int i = 0,a,b; i < M; i++){
        scan(a); scan(b);
        arr[a]--;
        arr[b+1]++;
    }
    for(int i = 1; i <= N; i++)
        arr[i] += arr[i-1];
    long long sum = 0;
    int w = INT_MAX, l = 1, r = 1;
    while(r <= N){
        while(sum < K && r <= N){
            sum += arr[r++];
        }
        while(sum >= K && l <= N){
            w = min(w, r-l);
            sum -= arr[l++];
        }
    }
    printf("%d\n", w == INT_MAX? -1: w);
    return 0;
}