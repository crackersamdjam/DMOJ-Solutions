#include <bits/stdc++.h>
using namespace std;
const int MM = 102;
int N,a[MM];
double d[MM];
int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", a+i);
    sort(a, a+N);
    for(int i = 1; i < N; i++){
        double val = ((double)a[i] - a[i-1])/2;
        d[i-1] += val;
        d[i] += val;
    }
    double ans = INFINITY;
    for(int i = 1; i < N-1; i++)
        ans = min(ans, d[i]);
    printf("%.1f\n", ans);
    return 0;
}