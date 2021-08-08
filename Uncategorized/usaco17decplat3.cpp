#include <bits/stdc++.h>
using namespace std;

const int MM = 1e5+2;

int n, a[MM];

bool test(int l){
    vector<int> v;
    for(int i = 1; i < l; i++)
        v.emplace_back(n-a[i]);
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        //more than (i+1) can jump in from of a[i]
        if(i+1 >= v[i])
            return 0;
    }
    return 1;
}

int main(){
    
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    int l = 1, m, r = n;
    while(l <= r){
        m = (l+r)/2;
        if(test(m))
             l = m+1;
        else
            r = m-1;
    }
    
    cout << n-r << '\n';
    
    return 0;
}