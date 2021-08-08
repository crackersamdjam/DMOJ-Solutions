#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 3e5+2;

int n, m, a[MM], bit[21][MM];

void update(int id, int i, int v){
    for(; i < MM; i += i&-i)
        bit[id][i] += v;
}

int query(int id, int i){
    int ret = 0;
    for(; i; i -= i&-i)
        ret += bit[id][i];
    return ret;
}

int main(){
    
    scan(n, m);
    
    for(int i = 1; i <= n; i++){
        scan(a[i]);
        update(a[i], i, 1);
    }
    
    for(int t = 0,op,l,r,k; t < m; t++){
        
        scan(op);
        
        if(op == 1){
            scan(k, l);
            update(a[k], k, -1);
            a[k] = l;
            update(a[k], k, 1);
            continue;
        }
        
        scan(l, r, k);
        
        for(int i = 20; i >= 0; i--){
            int v = query(i, r) - query(i, l-1);
            //print(l, r, i, v);
            if(v >= k){
                print(i);
                break;
            }
            k -= v;
        }
    }
    
    return 0;
}