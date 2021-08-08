#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}

using namespace std;
const int MM = 1e6+2;

int N, Q, a[MM], psa[MM];
vector<int> one;

int main(){
    
    one.push_back(0);
    
    scan(N, Q);
    
    for(int i = 1; i <= N; i++){
        scan(a[i]);
        psa[i] = psa[i-1] + a[i];
        if(a[i] == 1)
            one.push_back(i);
    }
    one.push_back(1e7);
    
    for(int t = 0,l,r,x; t < Q; t++){
        scan(l, r, x);
        assert(r <= N);
        assert(l > 0);
        int v = psa[r] - psa[l-1];
        if((v&1) == (x&1)){
            puts(v >= x ? "YES" : "NO");
        }
        else{
            int nl = (*lower_bound(one.begin(), one.end(), l))+1;
            int nr = (*--upper_bound(one.begin(), one.end(), r))-1;
            if((nr > 0 && nr <= N && psa[nr] - psa[l-1] >= x) || (nl <= N && nl > 0 && psa[r] - psa[nl-1] >= x))
                puts("YES");
            else
                puts("NO");
        }
    }
    
    return 0;
}