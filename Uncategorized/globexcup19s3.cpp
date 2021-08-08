#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 2e5+2;

int n, q[MM], l=1, r, al[MM], ar[MM];
__int128 d[MM], h[MM];

bool val(int k, int j, int i, int t){
    if(!t) return (h[k] - h[i])*(d[i] - d[j]) >= (d[i] - d[k])*(h[j] - h[i]);
    return (h[k] - h[i])*(d[i] - d[j]) <= (d[i] - d[k])*(h[j] - h[i]);
}

int main(){
    
    scan(n);
    for(int i = 1; i <= n; i++)
        scan(h[i]);
    for(int i = 2; i <= n; i++){
        scan(d[i]);
        d[i] += d[i-1];
    }
    
    for(int i = 1; i <= n; i++){
        while(l < r && val(q[r-1], q[r], i, 0))
            r--;
        al[i] = q[r];
        
        while(l <= r and h[i] >= h[q[r]])
            r--;
        q[++r] = i;
    }
    
    l = 1, r = 0;
    for(int i = n; i; i--){
        while(l < r && val(i, q[r-1], q[r], 1))
            r--;
        ar[i] = q[r];
        
        while(l <= r and h[i] >= h[q[r]])
            r--;
        q[++r] = i;
    }
    
    h[0] = -1;
    for(int i = 1; i <= n; i++)
        print(h[al[i]], h[ar[i]]);
    
    return 0;
}