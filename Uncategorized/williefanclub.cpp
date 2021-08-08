#include <bits/stdc++.h>
using namespace std;

int n, l = 1, r = 2, v;

int main(){
    cin >> n;
    while(r <= n){
        cout << "? " << l << ' ' << r << endl;
        cin >> v;
        if(v) l = r++;
        else r++;
    }
    cout << "! " << l << endl;
    
    return 0;
}