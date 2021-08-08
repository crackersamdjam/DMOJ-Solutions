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
    int a,b,c;
    cin>>a>>b>>c;
    cout<<c*max(a,b)<<'\n';

    
    return 0;
}