#include <bits/stdc++.h>
using namespace std;

void init(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
    #endif
}
const int MM = 1e6+2;
int n, last = -1e7, a[MM];
string s;

int main(){
    init();
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>s;
    for(int i = 0; i < n; i++){
        if(s[i]=='1')
            last = i;
        a[i] = i-last;
    }
    last = 1e7;
    for(int i = n-1; i >= 0; i--){
        if(s[i]=='1')
            last = i;
        a[i] = min(a[i], last-i);
    }
    cout<<accumulate(a, a+n, 0LL)<<'\n';
    
    return 0;
}