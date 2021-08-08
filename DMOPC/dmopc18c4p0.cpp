#include <bits/stdc++.h>
using namespace std;
int r,x,y;
struct st{
    int x, y, m;
};
int main(){
    scanf("%d%d%d",&r,&x,&y);
    st a[3];
    for(int i = 0; i < 3; i++){
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].m);
    }
    sort(a, a+3, [](st a, st b){return a.m < b.m;});
    int dis = abs(x-a[0].x)*abs(x-a[0].x) + abs(y-a[0].y)*abs(y-a[0].y);
    if(dis < r*r)
        printf("What a beauty!");
    else
        printf("Time to move my telescope!");
    return 0;
}