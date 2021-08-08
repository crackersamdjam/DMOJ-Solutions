#include <bits/stdc++.h>
#define MM 1002
using namespace std;
struct box{
    int vol,x,y,z;
}arr[MM];
int it[3],N,M;
inline bool cmp(box a, box b){
    return a.vol <= b.vol;
}
int main(){
    scanf("%d",&N);
    for(int i = 0; i < N; i++){
        scanf("%d%d%d",it,it+1,it+2);
        sort(it,it+3);
        arr[i] = {it[0]*it[1]*it[2],it[0],it[1],it[2]};
    }
    sort(arr,arr+N,cmp);
    scanf("%d",&M);
    for(int i = 0,a,b,c; i < M; i++){
        scanf("%d%d%d",it,it+1,it+2);
        sort(it,it+3);
        for(int j = 0; j <= N; j++){
            if(j == N){
                printf("Item does not fit.\n");
                break;
            }
            if(arr[j].x >= it[0] && arr[j].y >= it[1] && arr[j].z >= it[2]){
                printf("%d\n", arr[j].vol);
                break;
            }
        }
    }
    return 0;
}