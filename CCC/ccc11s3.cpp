#include <bits/stdc++.h>
using namespace std;

int T, M, X, Y, p, arr[5][5] = {{0,2,2,2,0},{0,1,2,1,0},{0,0,1,0,0},{0,0,0,0,0},{0,0,0,0,0}};

inline void go(int m, int x, int y){
    p = (int)pow(5,m-1);
    switch(arr[x/p][y/p]){
        case 0:
            printf("empty\n");
            break;
        case 1:
            if(m == 1)
                printf("empty\n");
            else
                go(m-1,x%p,y%p);
            break;
        case 2:
            printf("crystal\n");
            break;
    }
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d", &M, &X, &Y);
        go(M,Y,X);
    }
    return 0;
}