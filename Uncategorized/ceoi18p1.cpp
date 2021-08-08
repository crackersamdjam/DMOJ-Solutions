#pragma GCC optimize "Ofast"
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
const int MM = 100001;

ll dp[2][MM];
int n, m;

struct ss{
    int c, f, v;
} a[4000];

int main(){
    
    scan(n);
    
    for(int i = 0; i < n; i++){
        scan(a[i].c, a[i].f, a[i].v);
        a[i].v = -a[i].v;
    }
    
    scan(m);
    
    for(int i = n; i < n+m; i++){
        scan(a[i].c, a[i].f, a[i].v);
        a[i].c = -a[i].c;
    }
    
    sort(a, a+n+m, [](const ss &x, const ss &y){
        if(x.f != y.f)
            return x.f > y.f;
        return x.c > y.c;
    });
    
    memset(dp, -0x3f, sizeof dp);
    dp[1][0] = 0;
    
    for(int i = 0; i < n+m; i++){
        int id = i&1, p = id^1;
        for(int j = 0; j < MM; j++){
            dp[id][j] = dp[p][j];
            if(j >= a[i].c && j-a[i].c < MM)
                dp[id][j] = max(dp[p][j], dp[p][j-a[i].c] + a[i].v);
        }
    }
    
    int t = (n+m)&1^1;
    print(*max_element(dp[t], dp[t]+MM));
    
    return 0;
}