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
const int MM = 2e6+2;

int N;
ll L, a[MM], dp[MM];
deque<int> q;

inline double thing(int j, int k){
    j++, k++;
    return double(dp[j-1] - dp[k-1] + (sq(a[j-1]+j+L) - sq(a[k-1]+k+L)))/double(2*((a[j-1]+j+L)-(a[k-1]+k+L)));
    //if this is true, j is better than k
}

int main(){
    
    scan(N, L);
    
    for(int i = 1; i <= N; i++){
        scan(a[i]);
        a[i] += a[i-1];
    }
    
    q.push_front(0);
    
    for(int i = 1; i <= N; i++){
    
        while(q.size() > 1 && thing(q[0], q[1]) <= (a[i]+i))
            q.pop_front();
        
        dp[i] = dp[q[0]] + sq(a[i]-a[q[0]]+i-(q[0]+1)-L);
    
        //printf("%d %d %lld\n", i, q[0], dp[i]);
        
        while(q.size() > 1 && thing(q[q.size()-2], q.back()) > thing(q.back(), i))
            q.pop_back();
    
        q.push_back(i);
    }
    
    //print(dp[N]);
    printf("%lld\n", dp[N]);
    
    return 0;
}
/*
 
 when subtracting, a[j-1]
 
 dp[j-1] + (a[i] - a[j] + i - j - L))^2 <= dp[k-1] + (a[i]-a[j] + i - k - L))^2 ; k < j
 
 dp[j-1] + ((a[i]+i) - (a[j]+j+L))^2 <= dp[k-1] + ((a[i]+i) - (a[j]+k+L))^2
 
 dp[j-1] - dp[k-1] + (a[j]+j+L)^2 - 2(a[j]+j+L)(a[i]+i) <= (a[k]+k+L)^2 - 2(a[k]+k+L)(a[i]+i)
 
 dp[j-1] - dp[k-1] + (a[j]+j+L)^2 - (a[k]+k+L)^2 <= 2(a[j]+j+L)(a[i]+i) - 2(a[k]+k+L)(a[i]+i)
 
 dp[j-1] - dp[k-1] + (a[j]+j+L)^2 - (a[k]+k+L)^2 <= 2(a[i]+i)((a[j]+j+L)- (a[k]+k+L))
 
 (dp[j-1] - dp[k-1] (a[j]+j+L)^2 - (a[k]+k+L)^2))/2((a[j]+j+L)- (a[k]+k+L)) <= (a[i]+i)
 
 */