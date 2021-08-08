#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;

__int128 w, h, a, b, sx, sy, x, y, cnt;

#define sq(x) (x)*(x)

int main(){
    
    scan(w, h, a, b, sx, sy, x, y);
    w -= a, h -= b;
    
    if(!x || !y){
        string s = to_string((y*w + x*h)*2e6);
        return cout << s.substr(0, 6) << '\n', 0;
    }
    
    cnt = w*h*x*y/__gcd(w*y, h*x);
    
    long double ans = sqrtl(sq(cnt/x) + sq(cnt/y));
    cout << to_string(ans*2e6).substr(0, 6) << '\n';
    
    return 0;
}