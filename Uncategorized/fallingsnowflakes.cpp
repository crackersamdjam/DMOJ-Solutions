#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}

using namespace std;
const int MM = 5002, MN = 1e5;

int N, M, Q, bit[MM][MM], out[MN];

inline void update(int i, int j, int v){
    i++, j++;
    for(; i < MM; i += i&-i){
        for(int k = j; k < MM; k += k&-k)
            bit[i][k] += v;
    }
}

inline int query(int i, int j){
    i++, j++;
    int ret = 0;
    for(; i > 0; i -= i&-i){
        for(int k = j; k > 0; k -= k&-k)
            ret += bit[i][k];
    }
    return ret;
}

struct st{
    int op, t, a, b, c, d, id;
    friend bool operator<(const st &x, const st &y){
        if(x.t^y.t)
            return x.t < y.t;
        return x.op < y.op;
    }
};
vector<st> q;

int main(){
    
    scan(N, M, Q);
    
    for(int i = 0,a,b,l,r; i < M; i++){
        scan(a, b, l, r);
        q.push_back({1, l, a, b});
        q.push_back({-1, r, a, b});
    }
    
    for(int i = 0,op,a,b,c,d,t; i < Q; i++){
        op = gc;
        if(op == 'V'){
            scan(a, b, c, d, t);
            q.push_back({op, t, a, b, c, d, i});
        }
        else{
            scan(a, b, t);
            if(op == 'R')
                q.push_back({op, t, a, b, 1, N, i});
            else
                q.push_back({op, t, 1, N, a, b, i});
        }
    }
    
    sort(q.begin(), q.end());
    
    for(st t: q){
        if(t.op < 2)
            update(t.a, t.b, t.op);
        else if(t.op != 'V')
            out[t.id] = (query(t.b, t.d) - query(t.a-1, t.d) - query(t.b, t.c-1) + query(t.a-1, t.c-1));
        else
            out[t.id] = query(t.b, N) - query(t.a-1, N) + query(N, t.d) - query(N, t.c-1) -
            (query(t.b, t.d) - query(t.a-1, t.d) - query(t.b, t.c-1) + query(t.a-1, t.c-1));
    }
    
    for(int i = 0; i < Q; i++)
        print(out[i]);
    
    return 0;
}