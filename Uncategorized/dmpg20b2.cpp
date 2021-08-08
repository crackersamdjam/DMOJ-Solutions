#include <bits/stdc++.h>
using namespace std;

vector<string> v[3];
string s;
int n, p;
int main(){
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>s;
        v[i/(n/3)].emplace_back(s);
    }
    cin>>s;
    p += (s[0] == 's') + 2*(s[0] == 'g');
    for(auto i: v[p])
        cout<<i<<'\n';
    return 0;
}