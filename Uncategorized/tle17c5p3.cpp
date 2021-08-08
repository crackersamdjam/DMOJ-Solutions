#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int N = 201;

int n, ut[N];
bool m[N][N];

vector<int> u, ir, p;

int main(){
    
    scan(n);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int x = 0; x < n; x++){
                if((i*x - j + n) % n == 0){
                    //printf("%d*%d = %d\n", i, x, j);
                    m[i][j] = 1;
                    break;
                }
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        if(m[i][1]){
            u.push_back(i);
            ut[i] = 1;
        }
    }
    
    for(int i = 1; i < n; i++){
        if(ut[i])
            continue;
        
        bool g = 1;
        for(int a = 0; a < n; a++){
            for(int b = 0; b < n; b++){
                if(!ut[a] && !ut[b] && ((a*b-i+n)%n == 0)){
                    g = 0;
                    break;
                }
            }
        }
        
        if(g)
            ir.push_back(i);
        
        for(int a = 0; a < n; a++){
            for(int b = 0; b < n; b++){
                //if(a == b || a == i || b == i)
                  //  continue;
                if(m[i][a*b%n] && !m[i][a] && !m[i][b]){
                    //print(i, a, b);
                    goto out;
                }
            }
        }
        p.push_back(i);
        out:;
    }
    
    puts("Units:");
    for(int i: u)
        print(i);
    
    puts("Irreducibles:");
    for(int i: ir)
        print(i);
    
    puts("Primes:");
    for(int i: p)
        print(i);
    
    return 0;
}