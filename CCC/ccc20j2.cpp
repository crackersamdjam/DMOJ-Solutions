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
    int p, n, r, d;
    cin>>p>>n>>r;
    int t = n;
    for(d = 0; t <= p; d++){
        n *= r;
        t += n;
    }
    cout<<d;
    
    return 0;
}