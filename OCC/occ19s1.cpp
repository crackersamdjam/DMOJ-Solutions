#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;


int main(){
    
    int x1, x2, x3, x4, y1, y2, y3, y4;
    
    scan(x1, y1, x2, y2, x3, y3, x4, y4);
    
    if(x1 > x2)
        swap(x1, x2);
    if(y1 > y2)
        swap(y1, y2);
    if(x3 > x4)
        swap(x3, x4);
    if(y3 > y4)
        swap(y3, y4);
    if(min(x2, x4) - max(x1, x3) > 0)
        print((x2 - x1) * (y2 - y1) + (x4 - x3) * (y4 - y3) - max(0, (min(x2, x4) - max(x1, x3)) * (min(y2, y4) - max(y1, y3))));
    else
        print((x2 - x1) * (y2 - y1) + (x4 - x3) * (y4 - y3));
    
    return 0;
}