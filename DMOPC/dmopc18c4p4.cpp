#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}

using namespace std;
typedef long long ll;
const int MM = 2e5+2;

int N, Q, a[MM];
ll psa[MM], bit[MM], out[MM];

void update(int i, ll v){
    for(; i < MM; i += i&-i)
        bit[i] += v;
}

ll query(int i){
    ll ret = 0;
    for(; i > 0; i -= i&-i)
        ret += bit[i];
    return ret;
}

struct st{
    int v, op, i, l, r;
    friend bool operator<(const st &x, const st &y){
        if(x.v ^ y.v)
            return x.v > y.v;
        return x.op < y.op;
    }
};

vector<st> qs;

int main(){
    
    scan(N, Q);
    
    for(int i = 1; i <= N; i++){
        scan(a[i]);
        qs.push_back({a[i], 0, i});
        psa[i] = a[i] + psa[i-1];
    }
    
    for(int i = 0,l,r,k; i < Q; i++){
        scan(l, r, k);
        qs.push_back({k, 1, i, l, r});
    }
    
    sort(qs.begin(), qs.end());
    
    for(auto &q: qs){
        
        if(q.op == 0){
            update(q.i, q.v);
        }
        else{
            ll tot = psa[q.r] - psa[q.l-1];
            ll sum = query(q.r) - query(q.l-1);
            out[q.i] = sum - (tot-sum);
        }
    }
    for(int i = 0; i < Q; i++)
        print(out[i]);
    
    return 0;
}