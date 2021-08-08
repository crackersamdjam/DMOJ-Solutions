#include <bits/stdc++.h>
using namespace std;
int main() {
    char a,b,c;
    scanf("%c%c%c",&a,&b,&c);
    if(a == 'U' || a == 'D'){
        if(b == 'L' || b == 'R'){
            if(c=='U' || c == 'D'){
                if(c!=a){
                    printf("Candle\n");
                    return 0;
                }
            }
        }
    }else{
        if(b == 'U' || b == 'D'){
            if(c == 'L' || c == 'R'){
                if(c!=a){
                    printf("Crossover\n");
                    return 0;
                }
            }
        }
    }
    printf("Neither\n");
    return 0;
}