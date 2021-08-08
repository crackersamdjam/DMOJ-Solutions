#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

#ifndef ONLINE_JUDGE
template<typename T>
void printerr(T a){std::cout<<a<<std::endl;}
template<typename T,typename... Args>
void printerr(T a, Args... args) {std::cout<<a<<' ',printerr(args...);}
#else
template<typename... Args>
void printerr(Args... args){}
#endif

using namespace std;
using ll = long long;

int n, m;
ll ans;

int main(){
    scan(n, m);
    // alligned ones
    //i  = len, j = wid
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int x = n-i, y = m-j;
            //printerr("a", x, y, (ll)x*y);
            ans += (ll)x*y;
        }
    }
    //printerr("f", ans);
    // not alligned ones
    // i = rise, j = run
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int g = __gcd(i, j);
            //find other length
            for(int k = 1;; k++){
                int x = n-i - k*j/g, y = m-j - k*i/g;
                if(x < 0 or y < 0)
                    break;
                //print(i, j, x, y, (ll)x*y);
                ans += (ll)x*y;
            }
        }
    }
    print(ans);
    
    return 0;
}