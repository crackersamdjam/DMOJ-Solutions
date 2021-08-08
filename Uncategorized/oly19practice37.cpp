#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1201;

int a[MM][MM], hi[MM][MM], lo[MM][MM], n, m, l, ans = INT_MAX;

int main(){
    
    scan(n, m, l);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scan(a[i][j]);
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            lo[i][j] = INT_MAX;
            for(int k = j; k < j+l; k++){
                hi[i][j] = max(hi[i][j], a[i][k]);
                lo[i][j] = min(lo[i][j], a[i][k]);
            }
        }
    }
    
    for(int j = 0; j < m-l+1; j++){
        for(int i = 0; i < n-l+1; i++){
            int al = INT_MAX, am = -1;
            for(int ii = i; ii < i+l; ii++){
                al = min(al, lo[ii][j]);
                am = max(am, hi[ii][j]);
                if(ii >= n)
                    goto out;
            }
            //print(i, j, am, al);
            ans = min(ans, am - al);
            out:;
        }
    }
    
    print(ans);
    
    return 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            printf("%d ", lo[i][j]);
        pc(10);
    }
    pc(10);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            printf("%d ", hi[i][j]);
        pc(10);
    }
    
    return 0;
}
/*
4 4 2
1 2 3 4
9 8 7 1
2 4 65 3
3 2 1 2
 */