#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1e6+2;

struct st{
    int op, x, l, r;
    //op 0 = query and add, 1 = rm
    //at x = a_i.x, do on [l, r]
    bool operator <(const st &o) const{
        if(x == o.x)
            return op > o.op; //remove first
        return x < o.x;
    }
};
vector<st> q;

int n, bit[2][MM];
long long ans;

void up(int j, int i, int v){
    for(; i < MM; i += i&-i)
        bit[j][i] += v;
}

int get(int j, int i){
    int ret = 0;
    for(; i; i -= i&-i)
        ret += bit[j][i];
    return ret;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
#endif
    
    scan(n);

    for(int i = 0,a,b,c,d; i < n; i++){
        scan(a, b, c, d);
        d--;
        //r moves down to represent block
        //l stays same, block is above
        q.push_back({0, a, b, d});
        q.push_back({1, c, b, d});
    }
    
    sort(q.begin(), q.end());

    int in = 0;

    for(auto i: q){
        if(i.op == 0){
            
            //complementary counting
            ans += in - get(1, i.l-1) - (in - get(0, i.r));
            //all 'r's less than l,       all 'l's >= r
            
            up(0, i.l, 1);
            up(1, i.r, 1);
            in++;
        }
        else{
            up(0, i.l, -1);
            up(1, i.r, -1);
            in--;
        }
    }

    print(ans);
    
    return 0;
}