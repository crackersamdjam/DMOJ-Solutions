#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef long long ll;
const int MM = 5e4;

struct st{
    int p, c;
} a[MM];

int N, K, ans;
ll M;
priority_queue<int, vector<int>, greater<>> q;

int main(){
    
    scan(N, K, M);
    
    for(int i = 0; i < N; i++)
        scan(a[i].p, a[i].c);
    
    sort(a, a+N, [](st x, st y){
        return x.c < y.c;
    });
    
    for(int i = 0; i < K; i++){
        if(a[i].c > M)
            break;
        M -= a[i].c;
        q.push(a[i].p - a[i].c);
        ans++;
    }
    
    for(int i = K; i < N; i++){
        if(!q.empty() && a[i].c + q.top() < a[i].p){
            int v = a[i].c + q.top();
            if(v > M)
                continue;
            M -= a[i].c + q.top();
            q.pop();
            q.push(a[i].p - a[i].c);
        }
        else{
            if(a[i].p > M)
                continue;
            M -= a[i].p;
        }
        ans++;
    }
    
    print(ans);
    
    return 0;
}