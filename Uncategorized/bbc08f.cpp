#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

using namespace std;

int l, r;
long long ans;

int main(){
    
    int n, x;
    scan(n, x);
    
    l = r = x;
    
    for(int i = 0,ls,rs; i < n; i++){
        scan(ls, rs);
        if(rs < l){
            ans += abs(l-rs);
            r = l;
            l = rs;
        }
        else if(ls > r){
            ans += abs(ls-r);
            l = r;
            r = ls;
        }
        else{
            l = max(l, ls);
            r = min(r, rs);
        }
        //printf("%d %d %lld\n", l, r, ans);
    }
    
    print(ans);
    
    return 0;
}