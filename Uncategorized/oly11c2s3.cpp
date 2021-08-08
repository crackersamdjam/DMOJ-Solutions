#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1e5+1;

int N, M, c[MM], a[MM], v[MM];

int main(){
    
    scan(N, M);
    
    for(int i = 1; i <= N; i++)
        scan(a[i]);
    
    for(int i = 1; i <= M; i++)
        scan(c[i]);
    
    for(int i = M-1; i; i--)
        c[i] = min(c[i], c[i+1]);
    
    sort(a, a+N+1);
    
    for(int i = 1; i <= N; i++){
        v[i] = 1e9;
        for(int j = 1; j <= i; j++){
            v[i] = min(v[i], v[j-1] + c[a[i]-a[j]+1]);
        }
    }
    
    print(v[N]);
    
    return 0;
}