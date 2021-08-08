#include <bits/stdc++.h>
using namespace std;

long long suf[4];

long long f(string s){
    
    memset(suf, 0, 4<<4);
    
    for(char c: s){
        if(c == 'J')
            suf[3] += suf[2];
        else if(c == 'O')
            suf[2] += suf[1];
        else if(c == 'M')
            suf[1] += suf[0];
        else if(c == 'D')
            suf[0]++;
    }
    
    return suf[3];
}