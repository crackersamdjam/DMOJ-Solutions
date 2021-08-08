#include <bits/stdc++.h>
using namespace std;

string str;
int N, a[82];

int main(){
    
    cin >> N;
    
    while(N--){
        cin >> str;
        a[0] = 1;
        for(int i = 1; i <= str.length(); i++){
            if(str[i] == str[i-1])
                a[i] = a[i-1]+1;
            else{
                a[i] = 1;
                printf("%d %c ", a[i-1], str[i-1]);
            }
        }
        puts("");
    }
    
    return 0;
}