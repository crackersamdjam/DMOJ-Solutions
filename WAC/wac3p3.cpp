#include <bits/stdc++.h>
using namespace std;

string s, c[5];
int n, m, l, v[5], ans;

int main(){
    cin >> s >> m;
    for(int i = 0; i < m; i++)
        cin >> c[i] >> v[i];
    int z = 5;
    while(z--){
        for(int i = 1; i < m; i++){
            if(c[i-1].size() < c[i].size())
                swap(c[i-1], c[i]), swap(v[i-1], v[i]);
        }
    }
    ans = n = s.size();
    while(l < n){
        bool b = 0;
        for(int i = 0; i < m; i++){
            if(n-l >= c[i].size() and s.substr(l, c[i].size()) == c[i]){
                ans += v[i];
                l += c[i].size();
                b = 1;
                break;
            }
        }
        l += !b;
    }
    
    printf("%d\n", ans);
    
    
    return 0;
}