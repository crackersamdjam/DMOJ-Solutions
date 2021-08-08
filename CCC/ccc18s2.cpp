#include <bits/stdc++.h>
#define MM 102
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
int N, a[MM][MM];
bool row, col;
int main(){
    sc(N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            sc(a[i][j]);
    row = a[0][0] < a[N-1][0];
    col = a[0][0] < a[0][N-1];
    if(row){
        if(col){
            //0
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++)
                    printf("%d ", a[i][j]);
                printf("\n");
            }
        }else{
            //90
            for(int i = N-1; i >= 0; i--){
                for(int j = 0; j < N; j++){
                    printf("%d ", a[j][i]);
                }
                printf("\n");
            }
        }
    }else{
        if(col){
            //270
            for(int j = 0; j < N; j++){
                for(int i = N-1; i >= 0; i--)
                    printf("%d ", a[i][j]);
                printf("\n");
            }
        }else{
            //180
            for(int i = N-1; i >= 0; i--){
                for(int j = N-1; j >= 0; j--)
                    printf("%d ", a[i][j]);
                printf("\n");
            }
        }
    }
    
    return 0;
}