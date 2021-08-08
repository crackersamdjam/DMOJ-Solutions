#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

using namespace std;

int tc = 10, N, a[1001], ans;

int main(){
    
    
    
    while(tc--){
        ans = 0;
        scan(N);
        
        for(int i = 1; i <= N; i++)
            scan(a[i]);
        
        for(int t = N-1; t >= 1; t--){
            
            int ind = 0, at = N;
            
            for(int i = N; i; i--)
                if(a[i] == at)
                    at--;
            
            t = at;
            if(t == 0)
                break;
            
            for(int i = 1; i <= N; i++){
                if(a[i] == t){
                    ind = i;
                    break;
                }
            }
            
            if(ind == 1)
                continue;
            
            ans += ind-1;
            for(int i = ind; i >= 2; i--)
                a[i] = a[i-1];
            a[1] = t;
        }
        
        print(ans);
    }
    
    return 0;
}