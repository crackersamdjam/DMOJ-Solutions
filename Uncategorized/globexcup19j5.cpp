#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
const int MM = 1005;

ll base = 131, mod = 1685518853;
string a, b;
ll ha[MM], hb[MM], p[MM];
int n, l, r;

int main(){
    
    p[0] = 1;
    for(int i = 1; i < MM; i++)
        p[i] = p[i-1]*base % mod;
    
    cin >> a >> b;
    
    n = a.size();
    l = 0, r = n-1;
    while(a[l] == b[l] && l < n)
        l++;
    while(a[r] == b[r] && r > 0)
        r--;
    
    if(l > r) return 0*puts("aliens");
    
    a = a.substr(l, r-l+1);
    b = b.substr(l, r-l+1);
    //cout << a << ' ' << b << '\n';
    
    for(int i = 0; i < r; i++){
        ha[i] = (ha[i-1]*base + a[i]) % mod;
        hb[i] = (hb[i-1]*base + b[i]) % mod;
    }
    r = a.size();
    for(int i = 1; i < r; i++){
        int j = r-i;
        //cout << a.substr(0, i) << ' ' << a.substr(i) << ", " << b.substr(0, j) << ' ' << b.substr(j) << '\n';
        if(a.substr(0, i) == b.substr(j) and a.substr(i) == b.substr(0, j))
            return 0*puts("aliens");
    }
    
    puts("no aliens");
    
    return 0;
}