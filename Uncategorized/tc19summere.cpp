//solar
#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef long long ll;

ll ans, N, T;

int main(){
    
    scan(N, T);
    
    ans = N*N;
    
    ll num = N/T;
    
    ll rem = N % T;
    
    ll sz = (T-1)/2;
    
    if((T&1) == 0){
        ans -= num*(sz+1);
        //printf("even %lld\n", num*(sz+1));
        //add ends
    }
    
    ans -= num*sz*(sz+1);
    /*
    for(int i = 1; i <= sz; i++){
        ans -= 2*num*i;
        //printf("de %lld\n", 2*num*i);
    }
     */
    
    ll sz2 = (rem-1)/2;
    if((rem&1) == 0){
        ans -= sz2+1;
    }
    ans -= sz2*(sz2+1);
    /*
    for(int i = 1; i <= sz2; i++){
        ans -= 2*i;
    }
     */
    
    print(ans);
    
    
    return 0;
}