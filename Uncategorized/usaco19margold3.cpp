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
int n, a[MM], psl[MM], psr[MM];
vector<int> lone, lzero, rone, rzero;
ll ans, cntl, cntr, best = 1e18;

int main(){
    init();

    scan(n);
    for(int i = 1; i <= n; i++){
        scan(a[i]);
        psl[i] = psl[i-1] + a[i];
        if(!a[i]) cntl += psl[i];
        if(a[i])
            lone.emplace_back(i);
        else
            lzero.emplace_back(i);
    }
    for(int i = n+1; i <= n+n; i++){
        scan(a[i]);
        psr[i] = psr[i-1] + a[i];
        if(!a[i]) cntr += psr[i];
        if(a[i])
            rone.emplace_back(i);
        else
            rzero.emplace_back(i);
    }
    reverse(lzero.begin(), lzero.end());
    reverse(lone.begin(), lone.end());

    if(cntl == cntr)
        return puts("0"), 0;
    if(cntl and cntl != n and cntr and cntr != n) //if one side no 1/0, must swap
        best = abs(cntl - cntr);
    ll zl = cntl, zr = cntr, t = 0;
    for(int i = 0; i < min(lzero.size(), rone.size()); i++){
        int il = lzero[i], ir = rone[i];
        //print(i, il, ir);
        cntl -= psl[il-1]; //all 1s before (no 0s after)
        cntr -= n-psr[n+n]- (ir-n-psr[ir]); //sub all 0s after (no 1s before)
        t += ir-il;
        //print(i, t, cntl, cntr);
        best = min(best, t + abs(cntl - cntr));
        //print(i, best, cntl, cntr);
    }
    cntl = zl, cntr = zr, t = 0;
    for(int i = 0; i < min(lone.size(), rzero.size()); i++){
        int il = lone[i], ir = rzero[i];
        cntl = cntl + psl[il-1] - (n-il); //all 1 before - all 0 after
        cntr = cntr + n-psr[n+n] - (ir-n-psr[ir]) - (ir-1-n); //all 0 after - all 1 before
        t += ir-il;
        best = min(best, t + abs(cntl - cntr));
        //print(i, best, cntl, cntr);
    }

    print(best);

    return 0;
}