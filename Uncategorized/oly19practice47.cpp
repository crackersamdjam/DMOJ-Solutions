#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef long long ll;
const int MM = 2002;

int n, L, a[MM];
ll dp[MM][MM][2], inf = 0x3f3f3f3f3f3f3f3f;
bool done[MM][MM];
map<int, int> mp;

void go(int l, int r){
    if(done[l][r] || l == r)
        return;
    
    ll cnt = n+1 - (r-l);
    //print(l, r, cnt);
    
    go(l+1, r);
    go(l, r-1);
    done[l][r] = 1;
    dp[l][r][0] = min(dp[l+1][r][0] + cnt*(a[l+1] - a[l]), dp[l+1][r][1] + cnt*(a[r] - a[l]));
    dp[l][r][1] = min(dp[l][r-1][1] + cnt*(a[r] - a[r-1]), dp[l][r-1][0] + cnt*(a[r] - a[l]));
}

int main(){
    
    scan(n, L);
    
    a[0] = L;
    
    for(int i = 1; i <= n; i++)
        scan(a[i]);
    
    sort(a, a+n+1);
    
    int st = -1;
    for(int i = 0; i <= n; i++){
        if(a[i] == L){
            st = i;
            break;
        }
    }
    
    memset(dp, 0x3f, sizeof dp);
    
    dp[st][st][0] = dp[st][st][1] = 0;
    
    go(0, n);
    print(min(dp[0][n][0], dp[0][n][1]));
    
    return 0;
}