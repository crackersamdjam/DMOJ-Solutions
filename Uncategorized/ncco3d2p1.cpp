#include <bits/stdc++.h>
#define MM 50002
using namespace std;
int N, Q, l[16][MM], h[16][MM];
int main(){
    scanf("%d%d",&N,&Q);
    for(int i = 1; i <= N; i++){
        scanf("%d",&l[0][i]);
        h[0][i] = l[0][i];
    }
    for(int i = 1; i <= log2(N); i++){
        for(int j = 1; j+(1<<i)-1 <= N; j++){
            l[i][j] = min(l[i-1][j], l[i-1][j+(1<<(i-1))]);
            h[i][j] = max(h[i-1][j], h[i-1][j+(1<<(i-1))]);
        }
    }
    for(int i = 0,a,b; i < Q; i++){
        scanf("%d%d",&a,&b);
        int lvl = log2(b-a+1);
        printf("%d\n", max(h[lvl][a], h[lvl][b-(1<<lvl)+1]) -
            min(l[lvl][a], l[lvl][b-(1<<lvl)+1]));
    }
    return 0;
}