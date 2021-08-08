#include <bits/stdc++.h>
#define MM 10002
#define f first
#define s second
using namespace std;
typedef pair<int,char> pii;
int N,M,T;
pii arr[MM];
char c;
int main(){
    scanf("%d%d",&N,&M);
    scanf("%c",&c);
    for(int i = N-1; i >= 0; i--){
        scanf("%c",&c);
        arr[i] = {c,1};
    }
    scanf("%c",&c);
    for(int i = 0; i < M; i++){
        scanf("%c",&c);
        arr[i+N] = {c,2};
    }
    scanf("%d",&T);
    for(int t = 0; t < T; t++){
        for(int i = 0; i < N+M-1; i++){
            if(arr[i].s == 1 && arr[i+1].s == 2){
                pii temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                i++;
            }
        }
    }
    for(int i = 0; i < N+M; i++){
        printf("%c",arr[i]);
    }
    return 0;
}