#include <bits/stdc++.h>

using namespace std;

inline int num(string str){
    if(str == "1" or str == "one" or str == "un" or str == "一")
        return 1;
    if(str == "2" or str == "two" or str == "deux" or str == "二")
        return 2;
    if(str == "3" or str == "three" or str == "trois" or str == "三")
        return 3;
    if(str == "4" or str == "four" or str == "quatre" or str == "四")
        return 4;
    if(str == "5" or str == "five" or str == "cinq" or str == "五")
        return 5;
    if(str == "6" or str == "six" or str == "six" or str == "六")
        return 6;
    if(str == "7" or str == "seven" or str == "sept" or str == "七")
        return 7;
    if(str == "8" or str == "eight" or str == "huit" or str == "八")
        return 8;
    if(str == "9" or str == "nine" or str == "neuf" or str == "九")
        return 9;
    if(str == "10" or str == "ten" or str == "dix" or str == "十")
        return 10;
    return 0;
}

int main(){
    
    int N;
    string a, b;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        cout << num(a) + num(b) << '\n';
    }
    
    return 0;
}