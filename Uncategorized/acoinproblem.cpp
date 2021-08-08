#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

using namespace std;
const int MM = 1e5;

int N, V, a[MM], dp[MM];

struct query{
    int c, n, i, ans;
} q[MM];

int main(){
    
    memset(dp, 0x3f, sizeof dp);
    
    scan(N, V);
    
    for(int i = 1; i <= N; i++)
        scan(a[i]);
    
    for(int i = 0; i < V; i++){
        scan(q[i].c, q[i].n);
        q[i].i = i;
    }
    
    sort(q, q+V, [](query x, query y){
        return x.n < y.n;
    });
    
    dp[0] = 0;
    int last = -1;
    
    for(int i = 0; i < V; i++){
        while(last < q[i].n){
            last++;
            int v = a[last];
            
            for(int j = v; j < MM; j++)
                dp[j] = min(dp[j], dp[j-v]+1);
        }
        
        q[i].ans = dp[q[i].c];
    }
    
    sort(q, q+V, [](query x, query y){
        return x.i < y.i;
    });
    
    for(int i = 0; i < V; i++)
        print(q[i].ans == 0x3f3f3f3f? -1: q[i].ans);
    
    return 0;
}