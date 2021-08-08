#include <bits/stdc++.h>
using namespace std;

int n;
string s;
map<char, int> cnt;

int main(){
    cin>>n>>s;
    for(char c: s)
        cnt[c]++;
    cout<<min(min(min(cnt['p'], cnt['o']/2), cnt['k']), cnt['s']);
    return 0;
}