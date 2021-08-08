#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}

using namespace std;
const int MM = 1e5;
const double eps = 1e-6;

int N, a[MM];
double psa[MM], pmin[MM];

bool test(double m){
    
    pmin[0] = a[0]-m;
    
    for(int i = 1; i < N-1; i++){
        pmin[i] = min(pmin[i-1], psa[i] - (i+1)*m);
        if((psa[N-1]-N*m-(psa[i]-(i+1)*m)) + pmin[i-1] <= 0)
            return 1;
    }
    return 0;
}

int main(){
    
    scan(N);
    
    for(int i = 0; i < N; i++){
        scan(a[i]);
        psa[i] = psa[max(0, i-1)] + a[i];
    }
    
    double l = 0, m, r = 10000;
    while(r-l >= eps){
        m = (l+r)/2;
        if(test(m))
            r = m-eps;
        else
            l = m+eps;
    }
    
    printf("%.3lf\n", l);
    
    return 0;
}