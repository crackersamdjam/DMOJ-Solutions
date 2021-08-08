#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

#define bound(x) min(max((x), 1), N)

using namespace std;
const int MM = 1001;

int N, S, h[MM], a[MM], ans;

int main(){
    
    for(int tc = 5; tc--; ans = 0, memset(a, 0, sizeof a)){
    
        scan(N, S);
    
        for(int i = 1; i <= N; i++)
            scan(h[i]);
    
        while(1){
            int at = 1;
            while(a[at]){
                at++;
                if(at > N)
                    goto out;
            }
        
            int nx = at;
            for(int i = at+1; i <= bound(at + S); i++){
                
                for(int j = i-1; j > at; j--){
                    if(h[j] > h[i])
                        goto no;
                }
                nx = i;
                no:;
            }
            
            a[nx] = 1;
            for(int i = nx - 1; i >= bound(nx - S); i--){
                a[i] = 1;
                if(h[i] > h[nx])
                    break;
            }
            for(int i = nx + 1; i <= bound(nx + S); i++){
                a[i] = 1;
                if(h[i] > h[nx])
                    break;
            }
            ans++;
            assert(ans <= N);
        }
        out:;
        print(ans);
    
    }
    
    return 0;
}