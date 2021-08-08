#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;

int R, C, K;

inline int query(int x, int y){
    if(!x || !y || x > R || y > C)
        return INT_MAX;
    printf("? %d %d\n", x, y);
    fflush(stdout);
    int ans;
    scan(ans);
    return ans;
}

int main(){
    
    scan(R, C, K);
    
    int l = 1, m, r = R, ly = 1, my, ry = C, ans = 1e9;
    
    while(l <= r || ly <= ry){
        m = (l+r)/2;
        my = (ly + ry)/2;
        
        int a = query(m, my), b = query(m-1, my), c = query(m, my-1);
        
        if(a > b)
            r = m-1;
        else
            l = m+1;
        
        if(a > c)
            ry = my-1;
        else
            ly = my+1;
        
        ans = min(ans, min(a, min(b, c)));
    }
    
    printf("! %d\n", ans);
    fflush(stdout);
    
    return 0;
}