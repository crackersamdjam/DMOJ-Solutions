#include <bits/stdc++.h>
#define MM 100002
using namespace std;
int Q,a,b,c,i,psa[MM];
int main(){
    for(; c != '\n'; i++){
        c = getchar_unlocked();
        psa[i+1] = psa[i] + (c == 'G');
    }
    scanf("%d",&Q);
    while(Q--){
        scanf("%d%d",&a,&b);
        printf("%d\n", psa[b+1] - psa[a]);
    }
    return 0;
}