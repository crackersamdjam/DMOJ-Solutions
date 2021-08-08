#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using pii = pair<int, int>;
const int MM = 3e5+1;

int n, k, pre[MM];
pii mx[MM], my[MM];

struct st{
    int x, y, f, id;
    bool operator <(const st &o) const{
        if(x != o.x)
            return x < o.x;
        return y < o.y;
    }
} a[MM];

int main(){
    
    for(int i = 0; i < MM; i++)
        mx[i] = my[i] = {-1e9, -1e9};
    
    scan(n, k);
    
    for(int i = 1; i <= n; i++){
        scan(a[i].x, a[i].y, a[i].f);
        a[i].id = i;
    }
    
    sort(a+1, a+1+n);
    
    for(int i = 1; i <= n; i++){
        pii v = max(mx[a[i].x], my[a[i].y]);
        if(a[i].id == 1){
            v = {a[i].f, i};
        }
        else{
            if(v.first < k)
                continue;
            pre[i] = v.second;
            v = {v.first-k+a[i].f, i};
        }
    
        if(a[i].id == n){
            print(v.first);
            stack<int> ans;
            int cur = i;
            while(cur > 0){
                ans.push(cur);
                cur = pre[cur];
            }
            print(ans.size());
            while(!ans.empty()){
                int id = ans.top(); ans.pop();
                print(a[id].x, a[id].y);
            }
            return 0;
        }
        
        mx[a[i].x] = max(mx[a[i].x], v);
        my[a[i].y] = max(my[a[i].y], v);
    }
    
    return 0;
}