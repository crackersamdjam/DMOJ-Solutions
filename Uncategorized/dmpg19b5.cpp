#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}

using namespace std;
const int MM = 2e5+2;

int N;
struct st{
    int x, y, c, id;
} a[MM];

int main(){
    
    scan(N);
    
    for(int i = 0; i < N; i++){
        scan(a[i].x, a[i].y, a[i].c);
        a[i].id = i+1;
    }
    
    sort(a, a+N, [](st x, st y){
        if(x.x^y.x)
            return x.x < y.x;
        return x.y < y.y;
    });
    
    for(int i = 0; i < N-2; i++){
        if((a[i].c|a[i+1].c|a[i+2].c) == 3)
            return 0*printf("%d %d %d\n", a[i].id, a[i+1].id, a[i+2].id);
    }
    
    puts("-1");
    
    return 0;
}