#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

using namespace std;
const int MM = 3e5+1;
const double eps = 1e-6;

int N, K, a[MM];
double presum[MM], premin[MM];

int main(){
    
    scan(N, K);
    
    for(int i = 1; i <= N; i++)
        scan(a[i]);
    
    double l = 1, m, r = 1e6, cur;
    
    while(l <= r){
        m = (l+r)/2, cur = -1e6;
        
        premin[0] = 1e12;
    
        for(int i = 1; i <= N; i++){
            presum[i] = presum[i-1] + a[i] - m;
            premin[i] = min(premin[i-1], presum[i]);
            cur = max(cur, presum[i] - premin[max(0, i-K)]);
        }
        
        if(cur >= 0)
            l = m+eps;
        else
            r = m-eps;
    }
    
    printf("%lf\n", l);
    
    return 0;
}