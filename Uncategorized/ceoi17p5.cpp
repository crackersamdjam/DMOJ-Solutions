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
const int MM = 1e6+1;

int t;
char s[MM];

ll fpow(ll fpow_b, ll fpow_exp, ll fpow_mod){if(fpow_exp == 0) return 1;ll t = fpow(fpow_b,fpow_exp/2,fpow_mod);if(fpow_exp&1) return t*t%fpow_mod*fpow_b%fpow_mod;return t*t%fpow_mod;}

int main(){
    
    scanf("%d", &t);
    
    while(t--){
        
        scanf("%s", s);
    
        int l = 0, r = strlen(s)-1, lv = 0, rv = 0, cnt = 0;
        int lr = r;
        while(l < r){
            lv = lv*131 + s[l];
            rv = s[r]*fpow(131, lr-r, (1LL<<32)) + rv;
            //print(l, r, lv, rv);
            if(lv == rv){
                cnt += 2;
                lv = rv = 0;
                lr = r-1;
            }
            l++, r--;
            if(l == r || (l >= r && r != lr))
                cnt++;
        }
        
        print(max(cnt, 1));
    }
    
    return 0;
}