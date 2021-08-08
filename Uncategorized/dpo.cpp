#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}

using namespace std;
const int mod = 1e9+7;

int N, a[21], dp[1<<21][21];

int go(int mask, int n){
    
    if(n == N)
        return 1;
    
    int &ret = dp[mask][n];
    
    if(~ret)
        return ret;
    
    ret = 0;
    
    for(int i = 0; i < N; i++){
        if(a[i]&(1<<n) and !(mask&(1<<i)))
            ret = (ret + go(mask|(1<<i), n+1)) % mod;
    }
    
    return ret;
}

int main(){
    
    memset(dp, -1, sizeof dp);
    
    scan(N);
    
    for(int i = 0; i < N; i++){
        for(int j = 0,n; j < N; j++){
            scan(n);
            a[i] |= (n<<j);
        }
    }
    
    print(go(0, 0));
    
    return 0;
}
/*
 * loop through W
 * at each pt, recurse by using M_i and adding to mask
 * dp[2^21][21]
 */