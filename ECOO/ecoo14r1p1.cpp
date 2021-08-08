#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

using namespace std;
typedef long long ll;

int tc = 10;
ll D, H, M, T;

int main(){
    
    
    double R = (1.0*24*60*60)/((24*60+37)*60+22.663);
    
    while(tc--){
        scan(D, H, M);
        D--;
        T = M + 60*H + 60*24*D;
        
        T = R*T;
        
        printf("Day %lld, %02lld:%02lld\n", T/(24*60)+1, (T/60)%24, T%60);
    }
    
    return 0;
}