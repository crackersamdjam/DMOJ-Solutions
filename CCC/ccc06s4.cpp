#include <bits/stdc++.h>
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
const int MM = 102;
int N, a[MM][MM], id;
inline bool t1(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            for(int k = 1; k <= N; k++){
                if(a[i][ a[j][k] ] != a[ a[i][j] ][k]){
                    //printf("fail %d %d %d\n",i,j,k);
                    return 0;
                }
            }
        }
    }
    return 1;
}
inline bool t2(){
    for(int i = 1; i <= N; i++){
        bool pos = 1;
        for(int j = 1; j <= N; j++){
            if(a[i][j] != j || a[j][i] != j){
                pos = 0;
                break;
            }
        }
        if(pos){
            id = i;
            return 1;
        }
    }
    return 0;
}
inline bool t3(){
    for(int i = 1; i <= N; i++){
        bool pos = 0, pos2 = 0;
        for(int j = 1; j <= N; j++){
            if(a[i][j] == id)
                pos = 1;
            if(a[j][i] == id)
                pos2 = 1;
        }
        if(!pos || !pos2)
            return 0;
    }
    return 1;
}
int main(){
    while(1){
        sc(N);
        if(!N)
            break;
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                scanf("%d", &a[i][j]);
            }
        }
        if(!t1()){
            printf("no\n");
            continue;
        }
        if(!t2()){
            printf("no\n");
            continue;
        }
        if(!t3()){
            printf("no\n");
            continue;
        }
        printf("yes\n");
    }
    return 0;
}