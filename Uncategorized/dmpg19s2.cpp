#include <bits/stdc++.h>

using namespace std;

string k[10], d, e;

int main(){
    
    for(int i = 0; i < 10; i++)
        cin >> k[i];
    
    cin >> d;
    
    e = d;
    
    for(int i = 1; i < d.length(); i++){
        for(int j = 0; j < 10; j++){
            if(k[e[i-1]-'0'][j] == d[i]){
                e[i] = j+'0';
                break;
            }
        }
        //e[i] = k[d[i-1]-'0'][d[i]-'0'];
    }
    
    cout << e << '\n';
    
    string check = e;
    
    for(int i = 1; i < d.length(); i++){
        check[i] = k[e[i-1]-'0'][e[i]-'0'];
    }
    
    //cout << check << '\n';
    
    return 0;
}