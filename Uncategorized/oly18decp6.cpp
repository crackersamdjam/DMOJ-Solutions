#include <bits/stdc++.h>
#define f first
#define s second
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#define _CRT_SECURE_NO_WARNINGS
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
typedef pair<int, int> pii;
const int MM = 1002;

int N, ans = INT_MAX;
pii a[MM];
int main(){
    
    scan(N);
    for(int i = 0; i < N; i++){
        scan(a[i].f, a[i].s);
    }
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            int dif = a[i].f - a[j].f;
            int inc = a[j].s - a[i].s;
            if(!dif){
                ans = 0;
                break;
            }
            if(inc && dif % inc == 0 && dif/inc > 0)
                ans = min(ans, dif/inc);
        }
    }
    print(ans == INT_MAX? -1: ans);
    return 0;
}