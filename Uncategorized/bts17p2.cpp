#include <bits/stdc++.h>
using namespace std;
int G,e,p;
double ans = 1.0;
int main(){
    scanf("%d",&G);
    while(G--){
        scanf("%d%d",&e,&p);
        ans *= (1- (double)e/p);
    }
    printf("%lf",ans);
    return 0;
}