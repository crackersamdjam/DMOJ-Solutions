#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>

using namespace std;

string str;
vector<char> vec = {'A', 'B', 'X', 'Y'};
char sep;
/*
int press(string p){
    //cout << "p " << p << '\n';
    for(int len = ans.length(); len; len--){
        for(int j = 0; j+len <= p.length(); j++){
            
            if(ans.substr(0, len) == p.substr(j, len)){
                //cout << "found " << ans.substr(0, len) << "\n";
                return len;
            }
        }
    }
    return 0;
}
*/
string guess_sequence(int N){
    
    if(press("AB")){
        if(press("A"))
            sep = 'A';
        else
            sep = 'B';
    }
    else if(press("X"))
        sep = 'X';
    else
        sep = 'Y';
    
    str = sep;
    
    if(N == 1)
        return str;
    
    for(int i = 0; i < 4; i++){
        if(vec[i] == sep){
            vec.erase(vec.begin() + i);
            break;
        }
    }
    
    for(int i = 1; i < N-1; i++){
        
        int cnt = press((str + vec[0] + vec[0]) + (str + vec[0] + vec[1]) + (str + vec[0] + vec[2]) +
        (str + vec[1])) - i;
        
        if(cnt == 2)
            str += vec[0];
        else if(cnt == 1)
            str += vec[1];
        else
            str += vec[2];
    }
    
    if(press(str + vec[0]) == N)
        str += vec[0];
    else if(press(str + vec[1]) == N)
        str += vec[1];
    else
        str += vec[2];
    
    return str;
}