#include <bits/stdc++.h>
#define pc(x) putchar_unlocked(x)

using namespace std;

int main(){
    
    int N = 69;
    
    printf("69\n");
    
    for(int i = 2; i <= N; i++)
        printf("1 ");
    pc(10);
    
    for(int i = 2; i < N-1; i++){
        if(i&1){
            printf("100 100 1 ");
            for(int j = i+4; j <= N; j++)
                printf("100 ");
            pc(10);
        }
        else{
            printf("1 ");
            for(int j = i+2; j <= N; j++)
                printf("100 ");
            pc(10);
        }
    }
    
    printf("1\n");
    
    return 0;
}