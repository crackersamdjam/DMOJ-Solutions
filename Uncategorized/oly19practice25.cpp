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
const int MM = 5002;

ll p[MM][MM];
int n, m, k, q;

int main(){
    
    scan(n, m, k);
    
    for(int i = 0,a,b,c,d; i < k; i++){
        scan(a, b, c, d);
        c++, d++;
        p[c][d]++;
        p[c][b]--;
        p[a][d]--;
        p[a][b]++;
    }
    
    for(int i = 1; i <= n+1; i++){
        for(int j = 1; j <= m+1; j++){
            p[i][j] += p[i-1][j] + p[i][j-1] - p[i-1][j-1];
            //printn(p[i][j]);
        }
        //pc(10);
    }
    
    for(int i = 1; i <= n+1; i++){
        for(int j = 1; j <= m+1; j++){
            p[i][j] += p[i-1][j] + p[i][j-1] - p[i-1][j-1];
            //printn(p[i][j]);
            //pc(32);
        }
        //pc(10);
    }
    
    scan(q);
    
    for(int i = 0,a,b,c,d; i < q; i++){
        scan(a, b, c, d);
        a--, b--;//c++, d++;
        print(p[c][d] - p[c][b] - p[a][d] + p[a][b]);
        //print(p[c][d], p[c][b], p[a][d], p[a][b]);
    }
    
    return 0;
}