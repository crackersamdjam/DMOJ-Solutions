#include <bits/stdc++.h>
using namespace std;
string in;
inline bool go(string str){
    if(str.length() < 1)
        return 0;
    if(str == "A")
        return 1;
    if(str[0] == 'B' && str[str.length()-1] == 'S'){
        if(go(str.substr(1,str.length()-2)))
            return 1;
    }
    for(int i = 1; i <= str.length()-2; i++){
        if(str[i] == 'N')
            if(go(str.substr(0,i)) && go(str.substr(i+1)))
                return 1;
    }
    return 0;
}
int main(){
    while(1){
        cin >> in;
        if(in == "X")
            break;
        printf(go(in)? "YES\n": "NO\n");
    }
}