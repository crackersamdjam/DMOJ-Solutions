#include <bits/stdc++.h>
using namespace std;


int n;
char s[100002];
deque<char> d;
int main(){
    scanf("%d %s", &n, s);
    for(int i = 0; i < n; i++){
        if(d.empty() or s[i] <= d.front())
            d.push_front(s[i]);
        else
            d.push_back(s[i]);
    }
    for(auto i: d)
        cout<<i;
    
    return 0;
}