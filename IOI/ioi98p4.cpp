#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 20004, adj = 10002;

struct st{
    int op, x, l, r;
    bool operator <(const st &o) const{
        if(x == o.x)
            return op < o.op;
        return x < o.x;
    }
};

int n, ans, bl[MM];
vector<st> q;

int main(){
    
    scan(n);
    
    for(int i = 0,a,b,c,d; i < n; i++){
        scan(a, b, c, d);
        b += adj, d += adj;
        q.push_back({0, a, b, d});
        q.push_back({1, c, b, d});
    }
    
    sort(q.begin(), q.end());
    int cnt = 0, pre = 0;
    
    for(auto i: q){
        
        cnt = 0;
        for(int j = 1; j < MM; j++){
            if((bl[j] > 0 && bl[j-1] == 0) || (bl[j] == 0 && bl[j-1] > 0))
                cnt++;
        }
        ans += cnt*(i.x - pre);
        pre = i.x;
        if(i.op == 0){
            for(int j = i.l; j < i.r; j++){
                if(!bl[j]++)
                    ans++;
            }
        }
        else{
            for(int j = i.l; j < i.r; j++){
                if(!--bl[j])
                    ans++;
            }
        }
    }
    
    print(ans);
    
    return 0;
}