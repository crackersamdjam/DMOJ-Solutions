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
    string s, t;
    cin>>s>>t;
    for(int i = 0; i < t.size(); i++){
        rotate(t.begin(), t.begin()+1, t.end());
        if(~s.find(t))
            return cout<<"yes", 0;
    }
    cout<<"no";   
    return 0;
}