#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename T> void printmn(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}
template<typename First, typename ... Ints>
void printm(First arg, Ints... rest) {printmn(arg);pc(32);printmn(rest...);pc(10);}

using namespace std;
const int MM = 1e5;

int N, P, ans, mx, cnt;
struct st{
    int a, b;
    friend bool operator<(const st &x, const st &y){
        return x.b < y.b;
    }
} a[MM];

int main(){
    
    scan(N, P);
    
    for(int i = 0; i < N; i++){
        scan(a[i].a, a[i].b);
        if(i == P-1){
            ans = a[i].a;
            cnt = 1;
            a[i].b = INT_MAX;
            a[i].a = 0;
        }
    }
    
    sort(a, a+N);
    
    for(int i = 0; i < N-1; i++){
        if(a[i].b > ans)
            break;
        if(a[i].b > a[i].a)
            continue;
        
        ans += a[i].a - a[i].b;
        cnt++;
    }
    
    print(ans);
    print(cnt);
    
    return 0;
}