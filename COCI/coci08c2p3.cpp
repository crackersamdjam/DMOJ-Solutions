#include <bits/stdc++.h>
#define MM 11
using namespace std;
int b[MM], s[MM], N, ans = INT_MAX;
//b and s are reversed
void go(int a, int c, int n, int add){
    if(n > N){
        if(add)
            ans = min(ans, abs(a-c));
        return;
    }
    go(a*b[n], c + s[n], n+1, add+1);
    go(a, c, n+1, add);
}
int main(){
    scanf("%d",&N);
    for(int i = 1; i <= N; i++){
        scanf("%d%d",b+i,s+i);
    }
    go(1,0,1,0);
    printf("%d\n", ans);
    return 0;
}