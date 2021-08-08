#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;

int N;

int main(){
    
    scan(N);
    for(int i = 0,n; i < N; i++){
        scan(n);
        if(n < 1000)
            puts("Newbie");
        else if(n < 1200)
            puts("Amateur");
        else if(n < 1500)
            puts("Expert");
        else if(n < 1800)
            puts("Candidate Master");
        else if(n < 2200)
            puts("Master");
        else if(n < 3000)
            puts("Grandmaster");
        else if(n < 4000)
            puts("Target");
        else
            puts("Rainbow Master");
    }
    
    return 0;
}