#include <bits/stdc++.h>
using namespace std;
int N,f,l,val,pre,arr[200002];
bool b;
int main(){
    scanf("%d",&N);
    for(int i = 1,n; i <= N; i++){
        scanf("%d",arr+i);
        n = arr[i];
        if(n == 0){
            if(f == 0)
                f = i;
            else
                l = i;
        }
    }
    if(f && l){
        for(int i = f; i <= l; i++){
            if(arr[i] != 0){
                if(val != 0 && arr[i] != val){
                    b = 1;
                    break;
                }else{
                    val = arr[i];
                }
            }
        }
    }
    pre = arr[1];
    for(int i = 2; i <= N; i++){
        if(arr[i] != 0 && arr[i] < arr[i-1]){
            b = 1;
            break;
        }
    }
    printf(b? "NO": "YES");
    return 0;
}