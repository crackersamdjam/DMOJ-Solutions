#include <bits/stdc++.h>
#define sq(x) ((x)*(x))
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

using namespace std;
typedef long long ll;
const int MM = 1e6+1;

int N;
ll a, b, c, x[MM], dp[MM];
deque<int> q;

inline ll f(int k, int j){
    return a*sq(x[j]-x[k]) + b*(x[j]-x[k]) + c;
}

inline double thing(int k, int j){
    return double(dp[j] - dp[k] + a*(sq(x[j]) - sq(x[k])) - b*(x[j] - x[k])) / double(2*a*(x[j] - x[k]));
}

int main(){
    
    scan(N, a, b, c);
    
    for(int i = 1; i <= N; i++){
        scan(x[i]);
        x[i] += x[i-1];
    }
    
    q.push_back(0);
    
    for(int i = 1; i <= N; i++){
        
        while(q.size() > 1 and thing(q[0], q[1]) <= x[i])
            q.pop_front();
        
        dp[i] = dp[q[0]] + f(q[0], i);
    
        while(q.size() > 1 && thing(q[q.size()-2], q.back()) > thing(q.back(), i))
            q.pop_back();
    
        q.push_back(i);
    }
    
    print(dp[N]);
    
    return 0;
}
/*

dp[j] + thing(x[i]-x[j]) >= dp[k] + thing(x[i]-x[k]) ; k < j
dp[j] + a(x[i]-x[j])^2 + b(x[i]-x[j]) >= ...
dp[j] - dp[k] >= a(x[i]-x[k])^2 + b(x[i]-x[k]) - a(x[i]-x[j])^2 - b(x[i]-x[j])
same >= a((x[i]-x[k])^2 - (x[i]-x[j])^2) + b(x[i]-x[k] - (x[i]-x[j]))
same >= a((x[i]^2 -2*x[i]*x[k] + x[k]^2) - (x[i]^2 -2*a[i]*x[j] + x[j]^2) + b(x[j] - x[k])
same >= a(2*x[i]*(x[j] - x[k]) + x[k]^2 - x[j]^2) + b(x[j] - x[k])
dp[j] - dp[k] - b(x[j] - x[k]) >= a*2*x[i]*(x[j] - x[k]) + a*(x[k]^2 - x[j]^2)
dp[j] - dp[k] - b(x[j] - x[k]) - a*(x[k]^2 - x[j]^2) >= a*2*x[i]*(x[j] - x[k])
(dp[j] - dp[k] - b(x[j] - x[k]) + a*(x[j]^2 - x[k]^2))/(a*2*(x[j] - x[k])) <= x[i]    flip when dividing by a < 0
 
 */