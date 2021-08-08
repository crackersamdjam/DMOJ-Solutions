#include <bits/stdc++.h>
#define MM 3
using namespace std;
int a[MM],b[MM],c[MM],ans = 0;
int main(){
    scanf("%d%d%d",a+1,a+2,a);
    for(int i = 0; i < 3; i++)
        scanf("%d",b+i);
    for(int i = 0; i < 3; i++)
        scanf("%d",c+i);
    for(int i = 0; i < 3; i++){
        if(a[i] == b[i] && c[i] > 0)
            ans += c[i];
    }
    printf("%d\n",ans);
    return 0;
}