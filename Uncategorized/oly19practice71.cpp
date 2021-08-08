#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4,popcnt,abm,mmx,tune=native")

#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using ld = double;
const int MM = 500;

ld eps = 0.000001;
int n, k, x[MM], y[MM];

ld dis(ld x1, ld y1, ld x2, ld y2){
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

bool go(ld a, ld b, ld d){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(dis(a, b, x[i], y[i]) <= d*d+eps)
            cnt++;
    }
    return cnt >= k;
}

bool run(ld d){
    for(int a = 0; a < n; a++){
        for(int b = a+1; b < n; b++){
            ld mx = ld(x[a]+x[b])/2.0, my = ld(y[a]+y[b])/2.0, m = 0.0;
            if(x[a] != x[b]) m = -ld(x[a] - x[b])/(y[a]-y[b]);
            ld h = sqrt(d*d - dis(x[a], y[a], mx, my));
            ld dx = h/sqrt(1+m*m), dy = h*m/sqrt(1+m*m);
            if(go(mx-dx, my-dy, d) || go(mx+dx, my+dy, d))
                return 1;
        }
    }
    return 0;
}

int main(){
    
    scan(n, k);
    
    for(int i = 0; i < n; i++)
        scan(x[i], y[i]);
    
    ld l = 0, m, r = 14000;
    while(r-l > eps){
        m = (l+r)/2;
        if(run(m))
            r = m;
        else
            l = m+eps;
    }
    
    printf("%.5lf\n", r);
    
    return 0;
}