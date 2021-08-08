#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;

ll n, m, a, b, v[7][11], tot, ans;

int main(){
    
    scan(n, m, a, b);
    tot = min(n/a, m/b);
    
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 10; j++)
            scan(v[i][j]);
    }
    
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                for(int l = 0; l < 10; l++){
                    for(int p = 0; p < 10; p++){
                        for(int o = 0; o < 10; o++){
                            if(i+j+k+l+p+o <= tot){
                                ans = max(ans, v[0][i] + v[1][j] + v[2][k] + v[3][l] + v[4][p] + v[5][o]);
                            }
                        }
                    }
                }
            }
        }
    }
    
    print(ans);
    
    return 0;
}