#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;

void init(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
    #endif
}

const int MM = 2e5+5;
using ll = long long;
int n;
pair<ll, int> a[MM];
ll b[MM], pre[MM], suf[MM], ans[MM];

int main(){
    init();
    scan(n);
    for(int i = 1; i <= n+1; i++){
        scan(a[i].first);
        a[i].second = i;
    }
    for(int i = 1; i <= n; i++)
        scan(b[i]);
    sort(a+1, a+n+2);
    sort(b+1, b+n+1);

    for(int i = 1; i <= n; i++){
        pre[i] = max(pre[i-1], a[i].first-b[i]);
    }
    for(int i = n; i > 0; i--){
        suf[i] = max(suf[i+1], a[i+1].first-b[i]);
    }
    for(int i = 0; i <= n; i++){
        ans[a[i+1].second] = max(pre[i], suf[i+1]);
    }
    for(int i = 1; i <= n+1; i++)
        printf("%lld ", ans[i]);
    
    return 0;
}