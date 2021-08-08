#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 3e5+1;

int N, K;
long long ans;

struct st{
    int t, m, v, c;
};

vector<st> a;
priority_queue<int> q;

int main(){
    
    scan(N, K);
    
    for(int i = 0,m,v; i < N; i++){
        scan(m, v);
        a.push_back({0, m, v, 0});
    }
    
    for(int i = 0,c; i < K; i++){
        scan(c);
        a.push_back({1, 0, 0, c});
    }
    
    sort(a.begin(), a.end(), [](st x, st y){
        int v = max(x.m, x.c), w = max(y.m, y.c);
        if(v ^ w)
            return v < w;
        return x.t < y.t;
    });
    
    for(auto i: a){
        if(i.t){
            if(!q.empty()){
                ans += q.top();
                q.pop();
            }
        }
        else{
            q.push(i.v);
        }
    }
    
    print(ans);
    
    return 0;
}