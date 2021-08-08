#include <bits/stdc++.h>
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
const int MM = 100002;

int N, K, R, a[MM];
int main(){
    sc(N); sc(K); sc(R);
    for(int i = 0,k; i < K; i++){
        sc(k);
        if(k)
            a[k]++;
    }
    int cnt = 0, ans = 0;
    for(int i = 1; i < R; i++)
        cnt += a[i];
    for(int i = R; i <= N; i++){
        cnt += a[i];
        cnt -= a[i-R];
        while(cnt < 2){
            for(int j = i;; j--){
                if(!a[j]){
                    a[j]++;
                    cnt++;
                    ans++;
                    break;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}