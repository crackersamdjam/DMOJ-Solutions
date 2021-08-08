#include <bits/stdc++.h>

using namespace std;

int main(){
    
    double d = 0.0;
    int n;
    scanf("%d", &n);
    for(int i = 0,m; i < n; i++){
        scanf("%d", &m);
        d += m;
    }
    d /= n;
    printf("%.1lf\n", d);
    
    return 0;
}