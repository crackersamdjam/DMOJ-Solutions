#include <bits/stdc++.h>
#define block(nx) ((nx)/sz)
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

using namespace std;
const int MM = 2e5+1;

int N, Q, a[MM], cnt[MM], ans, sz, out[MM];

struct query{
    int l, r, id;
} in[MM];

int main(){
    
    scan(N);
    
    sz = sqrt(N)+1;
    
    for(int i = 1; i <= N; i++)
        scan(a[i]);
    
    scan(Q);
    
    for(int i = 0; i < Q; i++){
        scan(in[i].l, in[i].r);
        in[i].id = i;
    }
    
    sort(in, in+Q, [](query x, query y){
        if(block(x.l) == block(y.l))
            return x.r < y.r;
        return block(x.l) < block(y.l);
    });
    
    int l = 1, r = 1;
    cnt[a[1]]++;
    
    for(int i = 0; i < Q; i++){
        
        while(l > in[i].l){
            int val = ++cnt[a[--l]];
            if((val%2) == 0)
                ans++;
            else if(val != 1)
                ans--;
        }
        while(r > in[i].r){
            int val = --cnt[a[r--]];
            if(val%2)
                ans--;
            else if(val > 0)
                ans++;
        }
        while(r < in[i].r){
            int val = ++cnt[a[++r]];
            if((val%2) == 0)
                ans++;
            else if(val != 1)
                ans--;
        }
        while(l < in[i].l){
            int val = --cnt[a[l++]];
            if(val%2)
                ans--;
            else if(val > 0)
                ans++;
        }
        
        out[in[i].id] = ans;
    }
    
    for(int i = 0; i < Q; i++)
        print(out[i]);
    
    
    return 0;
}