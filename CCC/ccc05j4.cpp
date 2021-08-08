#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;

int no[22][22], w, h, w2, h2, t, cnt;

int main(){
    
    scan(w, h, w2, h2, cnt);
    
    for(int i = 0; i < 22; i++){
        no[i][0] = no[0][i] = 1;
        no[w+1][i] = no[i][h+1] = 1;
    }
    
    for(int i = 1; i <= w2; i++){
        for(int j = 1; j <= h2; j++){
            no[i][j] = 1;
            no[w-i+1][j] = 1;
            no[i][h-j+1] = 1;
            no[w-i+1][h-j+1] = 1;
        }
    }
    
    int x = w2+1, y = 1, d1 = 1, d2 = 0, n1 = 0, n2 = -1;
    
    while(1){
        if(!cnt--)
            break;
        
        no[x][y] = ++t;
        
        if(!no[x+n1][y+n2])
            d1 = n1, d2 = n2;
        else if(no[x+d1][y+d2]){
            n1 = d1, n2 = d2;
            if(d1)
                d2 = d1, d1 = 0;
            else
                d1 = -d2, d2 = 0;
        }
        if(no[x+d1][y+d2])
            break;
        
        x += d1, y += d2;
    }
    
    print(x);
    print(y);
    
    return 0;
    
    for(int i = 0; i < 22; i++){
        for(int j = 0; j < 22; j++){
            printf("%02d ",no[j][i]);
        }
        pc(10);
    }
    
    return 0;
}