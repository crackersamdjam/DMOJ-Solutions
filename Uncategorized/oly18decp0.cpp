#include <bits/stdc++.h>
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;


int main(){
    
    string str;
    getline(cin, str);
    str[0] += 'A'-'a';
    for(int i = 1; i < str.length(); i++){
        if(str[i] == '.' && i+2 < str.length() && str[i+2] >= 'a' && str[i+2] <= 'z'){
            str[i+2] += 'A'-'a';
        }
    }
    cout << str;
    
    return 0;
}