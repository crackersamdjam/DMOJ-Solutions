#include <bits/stdc++.h>
#define MM 102
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
pii arr[MM];
int N,P;
char names[MM][52];
int main(){
    scanf("%d%d",&N,&P);
    for(int i = 0; i < N; i++){
        scanf("%s",names[i]);
        arr[i].s = i;
    }
    for(int i = 0,t; i < P; i++){
        for(int j = 0; j < N; j++){
            scanf("%d",&t);
            arr[j].f += t;
        }
    }
    sort(arr,arr+N,greater<pii>());
    for(int i = 0 ; i < N; i++){
        printf("%d. %s\n",i+3,names[arr[i].s]);
    }
    return 0;
}