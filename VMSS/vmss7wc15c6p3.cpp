#include <bits/stdc++.h>
using namespace std;
const int MM = 4e5+1;

int N, par[MM], a[MM], ans = -1000;

int main(){
    
    scanf("%d", &N);
    
    for(int i = 0,a,b; i < N-1; i++){
        scanf("%d %d", &a, &b);
        par[b] = a;
    }
    
    for(int i = 1; i <= N; i++)
        scanf("%d", a+i);
    
    for(int i = N; i > 1; i--){
        ans = max(ans, a[i]);
        a[par[i]] += a[i];
    }
    
    ans = max(ans, a[1]);
    
    printf("%d\n", ans);
    
    return 0;
}