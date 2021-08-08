#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;

int T, N, B, dp[6][3002];
struct st{
    int c, v, t;
} a[3002];

int main(){
    
    scan(T, N);
    
    for(int i = 0; i < N; i++){
        scan(a[i].c, a[i].v, a[i].t);
    }
    scan(B);
    
    sort(a, a+N, [](st a, st b){return a.t < b.t;});
    
    for(int i = 1; i <= T; i++){
        for(int j = 0; j <= B; j++){
            for(int k = 0; k < N; k++){
                if(a[k].t != i || a[k].c > j)
                    continue;
                dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i-1][j-a[k].c] + a[k].v));
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= B; i++)
        ans = max(ans, dp[T][i]);
    
    print(ans);
    
    return 0;
}