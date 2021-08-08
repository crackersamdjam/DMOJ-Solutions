#include <bits/stdc++.h>
#define MM 50002
using namespace std;
struct st{
    int b,d,c,id;
}arr[MM];
int S,N,Q;
inline bool cmp(st a, st b){
    if(a.b == b.b && a.b >= S)
        return a.c > b.c;
    if(a.b == b.b)
        return a.d > b.d;
    return a.b > b.b;
};
int main(){
    scanf("%d%d",&S,&N);
    for(int i = 1,b,d,c; i <= N; i++){
        scanf("%d%d%d",&b,&d,&c);
        arr[i] = {b,d,c,i};
    }
    sort(arr+1,arr+1+N,cmp);
    scanf("%d",&Q);
    for(int i; Q--;){
        scanf("%d",&i);
        printf("%d\n", arr[i].id);
    }
    return 0;
}