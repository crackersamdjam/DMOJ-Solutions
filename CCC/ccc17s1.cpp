#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+1;

int N, a[MM], b[MM];

int main(){
    
    scanf("%d", &N);
    
    for(int i = 1; i <= N; i++){
        scanf("%d", a+i);
        a[i] += a[i-1];
    }
    
    for(int i = 1; i <= N; i++){
        scanf("%d", b+i);
        b[i] += b[i-1];
    }
    
    for(int i = N; i >= 0; i--){
        if(a[i] == b[i])
            return 0 * printf("%d\n", i);
    }
    
    return 0;
}