#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
typedef long long ll;
const int MM = 1e5+2;

int N, M;
ll g[MM], p[MM];

inline bool test(ll k){
    
    int last = 0;
    for(int i = 1; i <= M; i++){
        //group num
        
        //bs for endpoint
        int l = last, m, r = N;
        while(l <= r){
            m = (l+r)>>1;
            
            if(p[N]/k < g[i])
                return 1;
            
            if(p[m] - p[last] <= k*g[i]){
                
                if(m == N)
                    return 1;
                
                l = m+1;
            }
            else
                r = m-1;
        }
        //did not make any progress
        if(l-1 <= last)
            return 0;
        
        last = l-1;
    }
    
    return last == N;
}

int main(){
    
    scan(N, M);
    
    for(int i = 1; i <= N; i++){
        scan(p[i]);
        p[i] += p[i-1];
        //psa
    }
    
    for(int i = 1; i <= M; i++)
        scan(g[i]);
    
    ll ans = 1e14;
    
    sort(g+1, g+M+1);
    
    do{
        ll l = 1, m, r = 1e14;
        while(l <= r){
            m = (l + r)>>1;
            
            if(test(m))
                r = m - 1;
            else
                l = m + 1;
        }
        ans = min(ans, l);
        
    } while(next_permutation(g+1, g+M+1));
    
    print(ans);
    
    return 0;
}