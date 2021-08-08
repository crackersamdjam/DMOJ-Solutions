#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
typedef long long ll;
const int MM = 3000;

int N, a[MM];
ll dp[MM][MM];
bool vis[MM][MM];

ll go(int l, int r){
    if(vis[l][r])
        return dp[l][r];
    if(l == r)
        return a[l];
    vis[l][r] = 1;
    return dp[l][r] = max(a[l] - go(l+1, r), a[r] - go(l, r-1));
}

int main(){
    
    scan(N);
    
    for(int i = 0; i < N; i++)
        scan(a[i]);
    
    print(go(0, N-1));
    
    return 0;
}