#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long low = 1,high = 2000000000;
    long long mid = (low+high)/2;
    string str = "NORP";
    while(true){
        cout << mid << endl;
        fflush(stdout);
        //cout.flush();
        cin >> str;
        if(str == "OK") break;
        if(str == "SINKS"){
            low = mid;
        }else{
            high = mid;
        }
        mid = (low+high)/2;
    }
    return 0;
}