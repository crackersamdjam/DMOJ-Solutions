#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
#define sz(x) ((int)x.size())
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
const int MM = 1e5+2;

int n, a[MM][2], req[2], ava[2];
ll ans;

void go(int &x, int &y, int f){
    int sub = min(x, y);
    x -= sub, y -= sub;
    if(f)
        ans += sub;
}

int main(){
    scan(n);
    for(int i = 0,x,y,nx,ny; i < n*2; i++){
        scan(x, y);
        nx = max(1, min(n, x));
        ny = max(1, min(2, y));
        ans += abs(x-nx) + abs(y-ny);
        a[nx][ny-1]++;
    }
    for(int i = 1,sub; i <= n; i++){
        req[0]++, req[1]++;
        ava[0] += a[i][0], ava[1] += a[i][1];
        
        go(req[0], ava[0], 0);
        go(req[1], ava[1], 0);
        go(req[0], ava[1], 1);
        go(req[1], ava[0], 1);
        
        ans += req[0]+req[1]+ava[0]+ava[1];
    }
    
    print(ans);
    
    return 0;
}