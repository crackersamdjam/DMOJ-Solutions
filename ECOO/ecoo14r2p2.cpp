#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}

using namespace std;

int tc = 10, N, a[5], b[5], ans[5];

inline void go(int n){
    for(int k = 0; k < 5; k++){
        int i = a[k]/n, j = b[k]/n;
        if((i+j)&1^1){
            ans[k] ^= 1;
        }
    }
}

int main(){
    
    //freopen("DATA21.txt", "r", stdin);
    
    while(tc--){
        
        memset(ans, 0, sizeof ans);
        
        scan(N);
    
        for(int i = 0; i < 5; i++){
            scan(a[i], b[i]);
            a[i]--, b[i]--;
        }
    
        for(int i = 1; i * i <= N; i++){
        
            if(N % i == 0){
            
                go(i);
            
                if(N / i != i){
                
                    go(N / i);
                
                }
            }
        }
    
        for(int i = 0; i < 5; i++)
            pc(ans[i] ? 'B' : 'G');
        pc(10);
    }
    
    return 0;
}