#include <bits/stdc++.h>
#define MM 1002
using namespace std;
string a, b;
int c;
int main(){
    getline(cin,a);
    getline(cin,b);
    cin >> c;
    for(int i = 0; i < a.length(); i++){
        if(a[i] != b[i]){
            if(a[i] == ' ' || b[i] == ' '){
                c = -1;
                break;
            }
            c--;
            if(c < 0)
                break;
        }
    }
    printf( c < 0? "No plagiarism":"Plagiarized");
    return 0;
}