#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}

using namespace std;
typedef long long ll;
const int MM = 2e5+5;

int N, Q;
ll sp[21][MM];

ll query(int a, int b){
    if(a > b)
        return (ll)4e18;
    int k = 31-__builtin_clz(b-a+1);
    return min(sp[k][a], sp[k][b-(1<<k)+1]);
}

int main(){
    
    memset(sp, 0x3f, sizeof sp);
    
    scan(N, Q);
    
    for(int i = 1; i <= N; i++)
        scan(sp[0][i]);
    
    for(int k = 1; k <= 31-__builtin_clz(N)+1; k++)
        for(int i = 1; i+(1<<k) <= N+5; i++)
            sp[k][i] = min(sp[k-1][i], sp[k-1][i+(1<<(k-1))]);
    
    for(int i = 0,a,b; i < Q; i++){
        ll k;
        scan(k, a, b);
        while(1){
            int l = a, m, r = b;
            while(l <= r){
                m = (l+r)>>1;
                if(query(a, m) <= k)
                    r = m-1;
                else
                    l = m+1;
            }
            
            if(l > b)
                break;
            k %= query(a, l);
            
            if(!k || a == b || l > b)
                break;
            
            a = l+1;
        }
        print(k);
    }
    
    return 0;
}
/*
 * n % (n/2+1) = (n-1)/2
 * log n time to reduce to 0 iff elements < n (otherwise no effect)
 * when no more #s in range or n == 0, break
 *
 * bs rmq from (l, m)
 * to find earliest point where query(l, m) <= k
 * l = m+1
 * k %= query res
 */