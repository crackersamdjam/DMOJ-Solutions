#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef pair<int, int> pii;
const int MM = 1e4+1;

int n, l, w, a[MM], dif[MM], ans[101][MM], out[101][MM];
pii q[MM];

int main(){
    
    scan(n, l);
    for(int i = 1; i <= n; i++)
        scan(a[i]);
    
    scan(w);
    for(int i = 0; i < w; i++){
        scan(q[i].first);
        q[i].second = i;
    }
    sort(q, q+w);
    
    for(int len = 1; len <= n; len++){
        memset(dif, 0, sizeof dif);
        for(int i = 1; i+len <= n; i++){
            int j = i+len;
            if(a[i] != a[j])
                dif[max(0, i-l+1)]++, dif[i+1]--;
        }
        for(int i = 1; i+len+l-1 <= n; i++){
            dif[i] += dif[i-1];
            int id = lower_bound(q, q+w, make_pair(dif[i], 0)) - q;
            ans[id][i]++;
            ans[id][i+len]++;
        }
    }
    
    for(int i = 0; i < w; i++){
        if(i) for(int j = 0; j <= n-l+1; j++)
            ans[i][j] += ans[i-1][j];
        memcpy(out[q[i].second], ans[i], (n-l+2)*sizeof(int));
        for(int j = 1; j <= n-l+1; j++)
            assert(out[q[i].second][j] == ans[i][j]);
    }
    
    for(int i = 0; i < w; i++){
        for(int j = 1; j <= n-l+1; j++)
            printn(out[i][j]), pc(32);
        pc(10);
    }
    
    return 0;
}