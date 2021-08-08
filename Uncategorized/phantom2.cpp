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

ll N, M;
bool np[100000], b[20000001];
int ans, T;

int main(){
    
    
    scan(T);
    
    while(T--){
        
        memset(np, 0, sizeof np);
        memset(b, 0, sizeof b);
        ans = 0;
        
        scan(N, M);
    
        for(ll i = 2; i * i < M; i++){
            if(!np[i]){
            
                ll st = max(N - (N % i), i + i);
                while(st < N)
                    st += i;
            
                for(ll j = st; j < M; j += i)
                    b[j - N] = 1;
            
                for(ll j = i + i; j * j < M; j += i)
                    np[j] = 1;
            }
        }
    
        for(ll i = max(N, 2LL); i < M; i++)
            ans += !b[i - N];
    
        print(ans);
    }
    
    return 0;
}