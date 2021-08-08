#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using ll = long long;
const int MM = 5002, MN = 4e6+8, adj = 2e6+2;

int n, q, a[MM];
ll sum[MM][MM];
//std::unordered_map<int, ll> cnt;
int cnt[MN];

int main(){
    //freopen("threesum.in", "r", stdin); freopen("threesum.out", "w", stdout);
    scan(n, q);
    for(int i = 1; i <= n; i++){
        scan(a[i]);
        for(int j = 1; j < i; j++){
            cnt[adj+a[j]]--;
            sum[i][j] += cnt[adj-(a[i]+a[j])];
        }
        for(int j = 1; j <= i; j++)
            cnt[adj+a[j]]++;
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            sum[i][j] += sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1];
        }
    }
    
    for(int i = 0,l,r; i < q; i++){
        scan(l, r);
        l--;
        ll ans = sum[r][r] - sum[r][l] - sum[l][r] + sum[l][l];
        print(ans);
    }
    
    return 0;
}