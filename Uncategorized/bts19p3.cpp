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

ll n, m;
ll fpow(ll fpow_b, ll fpow_exp, ll fpow_mod){if(fpow_exp == 0) return 1;ll t = fpow(fpow_b,fpow_exp/2,fpow_mod);if(fpow_exp&1) return t*t%fpow_mod*fpow_b%fpow_mod;return t*t%fpow_mod;}


bool test(ll mid){
    ll rem = n, d = fpow(2, mid, LLONG_MAX);
    int cnt = 0;
    while(rem > 1){
        rem = (rem+d-1)/d;
        cnt++;
    }
    //print(mid, cnt);
    return cnt <= m;
}


int main(){
    
    scan(n, m);
    
    if(n == 1)
        return !pc('0');
    
    ll l = 1, mid, r = log2(n)+2;
    while(l <= r){
        mid = (l+r)/2;
        if(test(mid))
            r = mid-1;
        else
            l = mid+1;
    }
    
    print(l);
    
    return 0;
}