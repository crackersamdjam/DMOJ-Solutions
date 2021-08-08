#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;

stack<pair<int, int>> q;
int N;
long long ans;

int main(){
    
    scan(N);
    
    for(int i = 0,h,add; i < N; i++){
        
        scan(h);
        add = 1;
        
        while(!q.empty() && q.top().first < h){
            ans += q.top().second;
            q.pop();
        }
        if(!q.empty() && q.top().first == h){
            add += q.top().second;
            ans += q.top().second;
            q.pop();
        }
        if(!q.empty())
            ans++;
        
        q.push({h, add});
    }
    
    print(ans);
    
    return 0;
}