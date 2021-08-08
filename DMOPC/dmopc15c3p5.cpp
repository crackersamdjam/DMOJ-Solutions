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

int n, m, a[20], b[20];
map<ll, ll> cnt;
ll ans;

int main(){
    
    scan(n, m);
    int f = (n+m)/2;
    int s = (n+m)-f;
    for(int i = 0; i < f; i++){
        scan(a[i]);
        if(i >= n)
            a[i] = -a[i];
    }
    
    for(int i = 0; i < s; i++){
        scan(b[i]);
        if(f+i >= n)
            b[i] = -b[i];
    }
    
    for(int i = 0; i < (1<<f); i++){
        ll sum = 0;
        for(int j = 0; j < f; j++){
            if((i>>j)&1)
                sum += a[j];
        }
        cnt[sum]++;
    }
    
    for(int i = 0; i < (1<<s); i++){
        ll sum = 0;
        for(int j = 0; j < s; j++){
            if((i>>j)&1)
                sum += b[j];
        }
        ans += cnt[-sum];
    }
    
    print(ans-1);
    
    return 0;
}