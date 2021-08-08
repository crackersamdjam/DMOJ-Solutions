#include <bits/stdc++.h>
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
int arr[8],pre,cur;
int main(){
    sc(pre);
    sc(cur); arr[1] = cur;
    if(cur > pre){
        for(int i = 2; i < 8; i++){
            sc(arr[i]);
            if(arr[i] < arr[i-1]){
                printf("mixed");
                return 0;
            }
        }
        printf("ascending");
    }else{
        for(int i = 2; i < 8; i++){
            sc(arr[i]);
            if(arr[i] > arr[i-1]){
                printf("mixed");
                return 0;
            }
        }
        printf("descending");
    }
    return 0;
}