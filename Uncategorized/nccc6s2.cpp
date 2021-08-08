#include <bits/stdc++.h>
using namespace std;
const int MM = 1002;

int N, arr[MM][MM];

int main(){
    
    scanf("%d", &N);
    int cnt = 1, st = -1, ed = -1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &arr[i][j]);
            if(arr[i][j] != cnt && st == -1){
                st = j;
            }
            else if(arr[i][j] == cnt && st != -1 && ed == -1){
                ed = j;
            }
            cnt++;
        }
        if(st != -1 && ed == -1){
            ed = N;
        }
    }
    printf("%d\n", ed-st);
    
    return 0;
}