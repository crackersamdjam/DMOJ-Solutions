#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1e5+2;

int n, a[MM], low = 1e9, hi = -1;
double md, f, s;

int main(){
    
    scan(n);
    
    for(int i = 1; i <= n; i++){
        scan(a[i]);
        low = min(low, a[i]);
        hi = max(hi, a[i]);
    }
    
    sort(a+1, a+1+n);
    
    if(n % 2 == 0)
        md = (a[n/2] + a[n/2+1])/2.0;
    else
        md = a[n/2+1];
    
    int m = n/2;
    
    if(m % 2 == 0)
        f = (a[m/2] + a[m/2+1])/2.0;
    else
        f = a[m/2+1];
    
    sort(a+1, a+1+n, greater<int>());
    if(m % 2 == 0)
        s = (a[m/2] + a[m/2+1])/2.0;
    else
        s = a[m/2+1];
    
    
    printf("%d %d %.8lf %.8lf %.8lf\n", low, hi, f, md, s);
    
    return 0;
}