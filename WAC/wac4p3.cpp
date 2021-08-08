///reeeeeeeeeeeeeeeeeeeeeee

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
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

#define sq(x) (x)*(x)

using namespace std;
using ld = long double;
const int MM = 15;

int n, k;
ld sx[MM], sy[MM], vx[MM], vy[MM], S, inf = 1e69;

struct st{
    ld t, x, y;
} dp[MM][1<<MM];

struct pt{
    ld x, y;
};

pt at(int i, ld t){
    return {sx[i]+vx[i]*t, sy[i]+vy[i]*t};
}

//how much more time until intersect
ld inter(ld curx, ld cury, ld t, int i){
    pt pp = at(i, t);
    ld fx = pp.x-curx, fy = pp.y-cury;
    
    ld a = sq(vx[i]) + sq(vy[i]) - sq(S);
    ld b = 2*vx[i]*fx + 2*vy[i]*fy;
    ld c = sq(fx) + sq(fy);
    
    ld r1 = (-b + sqrtl(sq(b) - 4*a*c))/(2*a);
    ld r2 = (-b - sqrtl(sq(b) - 4*a*c))/(2*a);
    ld rt = max(r1, r2);
    
    //printerr("q", a, b, c, rt);
    
    return rt;
}

struct qu{
    ld t; int i, m;
    qu(ld _t = 0, int _i = 0, int _m = 0){
        t = _t, i = _i, m = _m;
    }
    bool operator<(const qu &o) const{
        return t > o.t; //reverse
    }
};

priority_queue<qu> q;

int main(){
    cin>>n>>S;
    k = (1<<n);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            dp[i][j].t = inf;
        }
    }
    
    for(int i = 0; i < n; i++){
        cin>>sx[i]>>sy[i]>>vx[i]>>vy[i];
        
        ld t = inter(0, 0, 0, i);
        pt pp = at(i, t);
        int m = (k-1)^(1<<i);
        
        dp[i][m] = {t, pp.x, pp.y};
        qu ins = {t, i, m};
        q.push(ins);
    }
    
    while(q.size()){
        auto cur = q.top(); q.pop();
        ld curx = dp[cur.i][cur.m].x;
        ld cury = dp[cur.i][cur.m].y;
//        printerr(cur.t, cur.i, cur.m, curx, cury);
        
        for(int j = 0; j < n; j++){
            if(cur.m&(1<<j)){
                ld t = cur.t + inter(curx, cury, cur.t, j);
                pt pp = at(j, t);
                int m = cur.m^(1<<j);
                
                if(t < dp[j][m].t){
                    dp[j][m] = {t, pp.x, pp.y};
                    q.push({t, j, m});
                }
            }
        }
    }
    ld ans = inf;
    for(int i = 0; i < n; i++){
        ans = min(ans, dp[i][0].t);
    }
    
    cout<<fixed<<setprecision(10)<<ans<<'\n';
    
    
    return 0;
}