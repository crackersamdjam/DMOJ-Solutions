#include <bits/stdc++.h>
#define MM 148736
using namespace std;
bool s[MM];
int N,X,cnt=0;
int main(){
    scanf("%d %d",&N,&X);
    for(int i = 2; i < N; i++){
        if(!s[i]){
            cnt += (N-i)/X + (N-i-1)/X + 2;
            for(int j = i*2; j <= N; j+=i)
                s[j] = 1;
        }
    }
    if(!s[N] && N > 1)
        cnt++;
    printf("%d\n",cnt);
    return 0;
}