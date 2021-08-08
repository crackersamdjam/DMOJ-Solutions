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

int n, m, k, a[30], b[30];
ll ans, sa[1<<24], sb[1<<24];

int main(){
    
    scan(n, k);
    
    m = n/2;
    n -= m;
    
    for(int i = 0; i < n; i++)
        scan(a[i]);
    
    for(int i = 0; i < m; i++)
        scan(b[i]);
    
    for(int i = 0; i < (1<<n); i++){
        ll s = 0;
        for(int j = 0; j < n; j++)
            if(i&(1<<j))
                s += a[j];
        sa[i] = s;
    }
    
    for(int i = 0; i < (1<<m); i++){
        ll s = 0;
        for(int j = 0; j < m; j++){
            if(i&(1<<j))
                s += b[j];
        }
        sb[i] = s;
    }
    
    sort(sa, sa+(1<<n));
    sort(sb, sb+(1<<m));
    
    int r = (1<<m)-1;
    for(int i = 0; i < (1<<n); i++){
        while(sa[i] + sb[r] > k){
            r--;
            if(r < 0)
                goto done;
        }
        ans += r+1;
    }
    done:;
    print(ans);
    
    return 0;
}