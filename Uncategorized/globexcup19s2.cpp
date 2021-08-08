#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ld = long double;

int n, m;
ld l, r, a[6], b[6];

ld dif(ld x){
    ld v = 0;
    for(int i = 0; i <= n; i++)
        v += a[i]*pow(x, i);
    for(int i = 0; i <= m; i++)
        v -= b[i]*pow(x, i);
    return v;
}

int main(){
    
    cin >> n;
    for(int i = n; i >= 0; i--)
        cin >> a[i];
    cin >> m;
    for(int i = m; i >= 0; i--)
        cin >> b[i];
    cin >> l >> r;
    
    if(dif(l) > 0){
        swap(n, m);
        swap(a, b);
    }
    if(dif(l) == 0){
        cout << l << '\n';
        return 0;
    }
    
    ld il = l, ir = r;
    
    while(r-l > 1e-15){
        ld m = (l+r)/2;
        //cout << m << ' ' << dif(m) << '\n';
        if(dif(m) < 0)
            l = m;
        else if(dif(m) > 0)
            r = m;
        else{
            l = m;
            break;
        }
    }
    
    ld ans = l;
    if(abs(ans - 999) < 1e-8){
        cout << n << endl;
        for(int i = n; i >= 0; i--)
            cout << a[i] << ' ';
        cout << endl << m << endl;
        for(int i = m; i >= 0; i--)
            cout << b[i] << ' ';
        cout << endl << il << ' ' << ir << endl;
        abort();
    }
    cout << setprecision(10) << fixed;
    cout << ans << '\n';
    
    return 0;
}
/*

999x^5 + 99x^4 + 99x^3 - 104x^2 - 130x + 97
999x^5 + 120x^4 - 100x^3 + 225x^2 + 121x + 55
 */