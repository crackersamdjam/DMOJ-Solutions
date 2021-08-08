#include <bits/stdc++.h>
using namespace std;
int M, N, K, a[30002][1002];
int main(){
    scanf("%d%d%d",&M,&N,&K);
    int x,y,r,b;
    while(K--){
        scanf("%d%d%d%d",&x,&y,&r,&b);
        x--, y--;
        for(int i = max(0, x-r),dif; i <= min(N-1, x+r); i++){
            dif = (int)sqrt(r*r - (x-i)*(x-i));
            a[max(0, y-dif)][i] += b;
            if(y+dif+1 < M)
                a[y+dif+1][i] -= b;
        }
    }
    int best = 0, cnt = 0;
    
    for(int i = 0,sum; i < N; i++){
        sum = 0;
        for(int j = 0; j < M; j++){
            sum += a[j][i];
            if(sum > best){
                best = sum;
                cnt = 1;
            }
            else if(sum == best)
                cnt++;
        }
    }
    printf("%d\n%d\n", best, cnt);
    return 0;
}