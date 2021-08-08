#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
const int MM = 2e5+2, MN = 502;
int N, Q, sz, n[MM], a[MN][MM];

inline int query(int l, int r, int x){
    //inclusive
    int ans = 0, st = (l-1)/sz + 1, ed = (r+1)/sz;
    for(int i = st; i < ed; i++)
        ans += a[i][x];
    
    for(int i = l; i < st*sz; i++)
        ans += (n[i] % x == 0);
    
    for(int i = ed*sz; i <= r; i++)
        ans += (n[i] % x == 0);
    
    return ans;
}

inline void update(int u, int v, int w){
    
    int ind = u/sz;
    
    for(int i = 1; i*i <= v; i++){
        if(v % i == 0){
            a[ind][i] += w;
            if(v/i != i)
                a[ind][v/i] += w;
        }
    }
}

int main(){
    
    scan(N, Q);
    
    sz = sqrt(N);
    
    for(int i = 0; i < N; i++){
        scan(n[i]);
        update(i, n[i], 1);
    }
    
    for(int i = 0,op,a,b,c; i < Q; i++){
        scan(op, a, b);
        a--;
        if(op == 1){
            b--;
            scan(c);
            printf("%d\n", query(a,b,c));
        }
        else{
            update(a, n[a], -1);
            n[a] = b;
            update(a, b, 1);
        }
    }
    return 0;
}