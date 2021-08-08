#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

//using namespace std;
typedef long double ld;
const int MM = 201;
ld lim = 2.5*2.5;

int n, ans;

struct st{
    ld x, y;
} pt[MM];

st cent(st a, st b, st c){
    ld a1 = b.x-a.x, b1 = b.y-a.y, c1 = (a1*a1 + b1*b1)/2;
    ld a2 = c.x-a.x, b2 = c.y-a.y, c2 = (a2*a2 + b2*b2)/2;
    ld d = a1*b2 - a2*b1;
    return {a.x + (c1*b2 - c2*b1)/d, a.y + (a1*c2 - a2*c1)/d};
}

#define sq(x) (x)*(x)
#define max(x, y) ((x) > (y) ? (x) : (y))

inline ld dist(st a, st b){
    return sq(a.x-b.x) + sq(a.y-b.y);
}

inline void test(st o){
    
    if(o.x < 0 || o.x > 50 || o.y < 0 || o.y > 50)
        return;
    
    int cnt = 0;
    for(int l = 0; l < n; l++){
        if(dist(o, pt[l]) <= lim){
            cnt++;
        }
    }
    ans = max(ans, cnt);
    //cout << o.x << ' ' << o.y << ' ' << cnt << '\n';
}

int main(){
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++){
        scanf("%Lf %Lf", &pt[i].x, &pt[i].y);
    }
    
    if(n == 1)
        return !printf("1");
    if(n == 2)
        return !printf(dist(pt[0], pt[1]) <= lim ? "2" : "1");
    
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                st o = cent(pt[i], pt[j], pt[k]);
                test(o);
            }
            //should also test colinear
            st o = {(pt[i].x+pt[j].x)/2, (pt[i].y+pt[j].y)/2};
            test(o);
        }
    }
    
    print(ans);
    
    return 0;
}