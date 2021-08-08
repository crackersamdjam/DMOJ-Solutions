#include <bits/stdc++.h>
using namespace std;

void init(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
    #endif
}



int main(){
    init();
    long double a,b;
    cin>>a>>b;
    printf("%.2Lf\n", a*b/4);

    
    return 0;
}