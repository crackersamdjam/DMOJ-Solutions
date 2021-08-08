#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
#define bound(x) min(x, D+1)
#define md(x) (x+mod)%mod
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
typedef long long ll;
const int MM = 1e5+2, mod = 1e9+7, MN = 70;

int X, D, N, P, fuel[MM], pt[MM];
ll suf[MM], w;

int main(){
    
    scan(X);
    if(X == 1){
        
        scan(D, N, P);
        fuel[0] = N;
        for(int i = 0,q,r; i < P; i++){
            scan(q, r);
            fuel[q] = r;
        }
        suf[D] = 1;
        for(int i = D-1; i >= 0; i--)
            suf[i] = md(suf[i+1]*2 - suf[bound(i+1+fuel[i])]);
        
        print(md(suf[0] - suf[1]));
    }
    else{
        puts("69 1 32");
        scan(w);
        w<<=1;
        for(int i = 1; i <= 32; i++){
            if(w&(1<<(i-1))){
                printf("%d %d\n", i, 68);
            }
            else{
                printf("%d %d\n", i, 32);
            }
        }
    }
    
    return 0;
}
/*
 * dif arr, update [i+1, i+fuel[i]] by dp[i]
 * get dp[N]
 *
 * w = 13
 * 1 2 3 4 8 end
 * 8, 4, and 1 have enough fuel to reach end, others dont
 *
 * 1, 4, 8, can reach end, others can jump only to 8
 */