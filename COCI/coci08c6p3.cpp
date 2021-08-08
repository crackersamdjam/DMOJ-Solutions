#include <bits/stdc++.h>
#define MM 102
using namespace std;
int arr[MM][MM],N,M,high;
int main(){
    memset(arr,0,sizeof(arr));
    scanf("%d%d",&N,&M);
    for(int i = 0,r,c; i < M; i++){
        scanf("%d%d",&r,&c);
        arr[r][c] = 1;
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
        }
    }
    for(int a = 1; a <= N; a++){
        //top
        for(int b = a; b <= N; b++){
            //bottom
            for(int c = 1; c <= N; c++){
                //left
                for(int d = c; d <= N; d++){
                    //right
                    int temp = arr[b][d] - arr[b][c-1] - arr[a-1][d] + arr[a-1][c-1];
                    if((b-a+1)*(d-c+1) == M && temp > high)
                        high = temp;
                }
            }
        }
    }
    printf("%d\n", M-high);
    return 0;
}