#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}

using namespace std;

inline bool cp(int x, int y){
    printf("C %d %d\n", x, y);
    //fflush(stdout);
    scan(x);
    return x;
}

inline void sw(int i, int j){
    printf("S %d %d\n", i, j);
    //fflush(stdout);
    scan(i);
}

int main(){
    
    int N;
    
    scan(N);
    
    for(int k = 10; k; k--){
        int len = (1<<k)-1;
        for(int i = len+1; i <= N; i++){
            for(int j = i; j > len and !cp(j-len, j); j -= len){
                sw(j-len, j);
                if(!cp(j-len, j))
                    break;
            }
        }
    }
    
    printf("A\n");
    //fflush(stdout);
    
    return 0;
}