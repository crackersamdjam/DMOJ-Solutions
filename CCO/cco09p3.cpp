#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1002;

int v, e, s, m, g, t;
int l1[MM], l2[MM], t1, t2;
int adj[MM][MM];
bool gd[MM];

int main(){
    
    scan(v, e, s, m, g, t);
    
    for(int i = 0,a,b,c; i < e; i++){
        scan(a, b, c);
        adj[a][b] = adj[b][a] = c;
    }
    
    for(int i = 0; i < s; i++)
        scan(l1[i]);
    
    for(int i = 0; i < m; i++)
        scan(l2[i]);
    
    for(int i = 0,n; i < g; i++){
        scan(n);
        gd[n] = 1;
    }
    
    int l = 0, r = 0;
    t++;
    while(t--){
        int a = l1[l], b = l1[l+1];
        int c = l2[r], d = l2[r+1];
        
        /*
        printf("%d -> %d, %d\n", a, b, t1);
        printf("%d -> %d, %d\n", c, d, t2);
        pc(10);
         */
        
        if(gd[a] || gd[c])
            return !puts("NO");
    
        //same spot on node
        if(a == c && t1 == t2)
            return !puts("YES");
        
        if(a == d && b == c){
            //meet on edge opposite direction
            if(t1 + t2 >= adj[a][b])
                return !puts("YES");
        }
        
        if(l < s-1 && ++t1 == adj[a][b])
            l++, t1 = 0;
        
        if(r < m-1 && ++t2 == adj[c][d])
            r++, t2 = 0;
    }
    
    return !puts("NO");
}