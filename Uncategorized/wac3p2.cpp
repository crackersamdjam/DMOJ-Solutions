#include <bits/stdc++.h>
using namespace std;



int main(){
    int n, a;
    cin >> n;
    while(n--){
        cin >> a;
        long long b = a/3, c = (a-b)/2, d = a-b-c;
        cout << b*c*d << '\n';
    }
    
    return 0;
}