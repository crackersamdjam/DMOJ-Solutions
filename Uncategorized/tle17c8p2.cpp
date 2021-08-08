#include <bits/stdc++.h>
using namespace std;
const int MM = 1001;
double H;
int D, E, a[MM];
struct{
    int a, s;
} m[6];
int main(){
    scanf("%lf%d%d",&H,&D,&E);
    for(int i = 0; i < D; i++){
        scanf("%d%d", &m[i].a, &m[i].s);
    }
    for(int i = 0,t,l,x; i < E; i++){
        scanf("%d%d%d", &t, &l, &x);
        a[t] += x;
        if(t+l < MM)
            a[t+l] -= x;
    }
    for(int i = 0; i < MM; i++){
        if(i)
            a[i] += a[i-1];
        double sub = a[i];
        for(int j = 0; j < D; j++){
            sub = min(sub, (a[i]-m[j].s)*(1.0-m[j].a/100.0));
        }
        H -= max(0.0, sub);
        if(H <= 0){
            printf("DO A BARREL ROLL!\n");
            return 0;
        }
    }
    printf("%.2lf\n", H);
    return 0;
}