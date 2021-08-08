#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
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
const int MM = 5e6+2;
int n, q, a[MM];
pair<int, int> pre[MM], suf[MM];

int main(){
    init();
    scan(n, q);
    pre[0] = suf[n+1] = {INT_MIN, 0};
    for(int i = 1; i <= n; i++){
        scan(a[i]);
        pre[i] = max(pre[i-1], {a[i], -i});
    }
    for(int i = n; i; i--)
        suf[i] = max(suf[i+1], {a[i], i});
    
    while(q--){
        int m;
        scan(m);
        print(-pre[m-1].second, suf[m+1].second);
    }

    return 0;
}