#include <bits/stdc++.h>

using namespace std;



int main(){
    
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            for(int k = 0; k <= 100; k++){
                if(a*i + b*j + c*k == d){
                    puts("QUEST CLEARED");
                    return 0;
                }
            }
        }
    }
    
    puts("TRY AGAIN");
    
    return 0;
}