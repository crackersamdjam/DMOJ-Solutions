#include <bits/stdc++.h>
using namespace std;
const int MM = 1001;

int N, a[MM], b[MM], ans;

int main(){
    
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++){
        scanf("%d%d", a+i, b+i);
    }
    a[N] = a[0], b[N] = b[0];
    
    for(int i = 0; i < N; i++){
        ans += a[i]*b[i+1];
        ans -= a[i+1]*b[i];
    }
    
    printf("%d\n", (abs(ans)+1)/2);
    
    return 0;
}