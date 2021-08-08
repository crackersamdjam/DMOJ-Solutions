#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;

int n, K, dp[201][201][7][2];
bool done[201][201][7][2];
char a[201];

int go(int l, int r, int k, int c){
    k = max(k, 0);
    
    int &ret = dp[l][r][k][c];
    if(done[l][r][k][c])
        return ret;
    
    done[l][r][k][c] = 1;
    
    if(l > r){
        if(k == 0)
            return ret = 0;
        return ret;
    }
    
    if(c == a[l])
        return ret = go(l+1, r, k-1, c);
        
    for(int m = l; m < r; m++)
        ret = min(ret, go(l, m, K, !c) + 1 + go(m+1, r, k, c));
        //remove [l, m]
    
    return ret;
}

int main(){
    
    memset(dp, 0x3f, sizeof dp);
    
    scanf("%d %d", &n, &K);
    scanf("%s", a);
    
    for(int i = 0; i < n; i++){
        a[i] = (a[i] == 'G');
        dp[i][i][1][a[i]] = 0;
    }
    
    int ans = min(go(0, n-1, K, 0), go(0, n-1, K, 1));
    print(ans == 0x3f3f3f3f ? -1 : ans+1);
    
    return 0;
}