#include <bits/stdc++.h>
#define MM 3164
using namespace std;
int N,p[MM],pt=0;
bool np[MM];
int main(){
    for(int i = 2; i < MM; i++){
        if(!np[i]){
            for(int j = i*2; j < MM; j+=i){
                np[j] = 1;
            }
            p[pt++] = i;
        }
    }
    scanf("%d",&N);
    for(int i = 0,m; i < N; i++){
        scanf("%d",&m);
        if(m >= MM || np[m]){
            for(int j = 0; j < pt; j++){
                while(m % p[j] == 0){
                    m /= p[j];
                    printf("%d ",p[j]);
                }
                if(p[j] == 1)
                    break;
            }
            if(m > 1)
                printf("%d ",m);
            printf("\n");
        }else
            printf("%d\n",m);
    }
    return 0;
}