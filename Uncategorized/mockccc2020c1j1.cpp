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
    int a[4];
    cin>>a[0]>>a[1]>>a[2]>>a[3];
    cout<<*min_element(a,a+4)<<'\n'<<*max_element(a,a+4)<<'\n';

    
    return 0;
}