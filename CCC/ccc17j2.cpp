#include <iostream>
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _,buf[7];
int N,s;
short k,i;
int main(){
    sc(N); sc(k);
    s = N;
    while(k--){
        N *= 10;
        s += N;
    }
    buf[6] = '\n';
    i = 5;
    while(s){
        buf[i--] = s % 10 + '0';
        s /= 10;
    }
    while(buf[i] != '\n')
        putchar_unlocked(buf[++i]);
    return 0;
}