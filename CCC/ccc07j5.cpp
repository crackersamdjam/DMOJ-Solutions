#include <bits/stdc++.h>
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
typedef long long ll;

int A, B, N;
int a[36] = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
ll dp[36];
int main(){
    
    scan(A, B, N);
    for(int i = 14; i < 14+N; i++){
        scan(a[i]);
        assert(a[i] <= 7000);
    }
    sort(a, a+14+N);
    dp[0] = 1;
    for(int i = 1; i < 14+N; i++){
        for(int j = 0; j < i; j++){
            int d = a[i] - a[j];
            if(d >= A && d <= B){
                dp[i] += dp[j];
            }
        }
    }
    print(dp[14+N-1]);
    return 0;
}
/*
 The third line of the input is an integer N (0≤N≤20),
 followed by N lines,
 each giving the location m of an additional eligible motel (0<m<7000).
 */