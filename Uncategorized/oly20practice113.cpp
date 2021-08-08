#include <bits/stdc++.h>
using namespace std;

// pi[i] = length of longest suffix (ending at i) with the same prefix as s
vector<int> kmp(string s){
    vector<int> pi(size(s));
    pi[0] = 0;
    for(int i = 1; i < size(s); i++){
        int j = pi[i-1];
        while(j and s[i] != s[j])
            j = pi[j-1];
        if(s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s, t;
    cin>>s>>t;
    s = t+"#"+s;
    auto v = kmp(s);
    int ans = 0;
    for(int i = size(t); i < size(v); i++)
        ans += v[i] == size(t);
    
    cout<<ans<<'\n';
}