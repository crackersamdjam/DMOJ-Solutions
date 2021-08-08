#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(32);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}

using namespace std;

int N, K;

int main(){
    
    scan(N, K);
    
    if(K < sqrt(N))
        return 0*puts("-1");
    
    for(int i = 1; i <= K; i++){
        for(int j = max(1, N-K*i+1); j <= N-K*(i-1); j++)
            print(j);
        
        if(N-K*i+1 < 1)
            break;
    }
    
    return 0;
}