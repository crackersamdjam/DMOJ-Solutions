#include <bits/stdc++.h>
#define MM 10002
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
int N, T = 5;
int a[MM];
int main(){
    while(T--){
        sc(N);
        memset(a,0,sizeof(a));
        for(int i = 2; i <= N; i++){
            int num = i;
            for(int j = 2; j <= i; j++){
                if(j > num)
                    break;
                while(num % j == 0){
                    a[j]++;
                    num /= j;
                }
            }
        }
        int st;
        for(int i = 2; i <= N; i++){
            if(a[i]){
                printf("%d^%d", i, a[i]);
                st = i;
                break;
            }
        }
        for(int i = st+1; i <= N; i++){
            if(a[i]){
                printf(" * %d^%d", i, a[i]);
            }
        }
        printf("\n");
    }
    return 0;
}