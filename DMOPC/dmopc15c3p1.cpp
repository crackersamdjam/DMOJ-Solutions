#include <bits/stdc++.h>
using namespace std;
int a,b,c,d;
bool e;
int main(){
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(a <= c && b > c)
        e = 1;
    else if(a > c && d > a)
            e = 1;
    printf(e ? "YES" : "NO");
    return 0;
}