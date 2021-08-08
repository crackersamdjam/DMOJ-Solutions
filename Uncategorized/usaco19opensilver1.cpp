#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1002;

int n, a[MM][MM], b[MM][MM], fx[MM], fy[MM];

bool run(int x, int y){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            b[i][j] = a[i][j];
    }
    b[x][y] ^= 1;
    for(int i = 0; i < n; i++){
        if(b[0][i]){
            //flip col
            for(int j = 0; j < n; j++)
                b[j][i] ^= 1;
        }
        if(b[i][0]){
            //flip col
            for(int j = 0; j < n; j++)
                b[i][j] ^= 1;
        }
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(b[i][j])
                return 0;
    return 1;
}

int main(){
    
    scan(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            a[i][j] = (gc == 'R');
        gc;
    }
    
    for(int i = 0; i < n; i++){
        if(a[0][i]){
            //flip col
            for(int j = 0; j < n; j++)
                a[j][i] ^= 1;
        }
    }
    
    for(int i = 0; i < n; i++){
        if(a[i][0]){
            //flip row
            for(int j = 0; j < n; j++)
              a[i][j] ^= 1;
        }
    }
    
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cnt += a[i][j];
        }
    }
    
    if(cnt == 1){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j])
                    return print(i+1, j+1), 0;
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        if(run(0, i))
            return print(1, i+1), 0;
    }
    
    for(int i = 0; i < n; i++){
        if(run(i, 0))
            return print(i+1, 1), 0;
    }
    
    puts("-1");
    
    return 0;
}