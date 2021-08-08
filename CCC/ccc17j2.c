#include <stdio.h>
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
int N,s;
short k;
int main(){
    sc(N); sc(k);
    s = N;
    while(k--){
        N *= 10;
        s += N;
    }
    printf("%d",s);
}