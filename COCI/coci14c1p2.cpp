#include <bits/stdc++.h>
using namespace std;
int N,hx,hy,lx,ly,x,y;
int main(){
    lx = ly = INT_MAX;
    scanf("%d",&N);
    while(N--){
        scanf("%d%d",&x,&y);
        lx = min(lx,x);
        hx = max(hx,x);
        ly = min(ly,y);
        hy = max(hy,y);
    }
    printf("%d\n",(max(hx-lx, hy-ly)*max(hx-lx, hy-ly)));
    return 0;
}