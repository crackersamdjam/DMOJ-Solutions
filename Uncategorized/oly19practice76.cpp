#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

void init(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
    #endif
}

using namespace std;
const int MM = 2001;

int n, a[20], sum, ans = 1e9;
bool dp[MM][MM];

int main(){
    init();
    scan(n);
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        scan(a[i]);
        sum += a[i];
        for(int j = MM-1; j >= 0; j--){
            for(int k = MM-1; k >= 0; k--){
                if(j >= a[i])
                    dp[j][k] |= dp[j-a[i]][k];
                if(k >= a[i])
                    dp[j][k] |= dp[j][k-a[i]];
            }
        }
    }

    for(int j = 0; j < MM; j++){
        for(int k = 0; k < MM; k++){
            if(dp[j][k]){
                int r = sum-j-k;
                ans = min(ans, max(j, max(k, r)));
            }
        }
    }

    print(ans);
    
    return 0;
}