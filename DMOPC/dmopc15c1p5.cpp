#include <bits/stdc++.h>
#define MM 252
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
int arr[MM][MM],W,H,N,ans;
int main(){
    sc(W); sc(H); sc(N);
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            sc(arr[i][j]);
            arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
        }
    }
    for(int h = 1,w; h <= N; h++){
        w = min(N/h, W);
        for(int i = h; i <= H; i++)
            for(int j = w; j <= W; j++)
                ans = max(ans, arr[i][j] - arr[i-h][j] - arr[i][j-w] + arr[i-h][j-w]);
    }
    printf("%d\n",ans);
    return 0;
}