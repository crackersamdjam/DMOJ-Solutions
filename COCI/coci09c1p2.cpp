#include <bits/stdc++.h>
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
int N, sum;
int main(){
    sc(N);
    for(int i = 0; i <= N; i++)
        for(int j = i; j <= N; j++)
            sum += i+j;
    printf("%d\n", sum);
    return 0;
}