#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1e5;

int N, Q, a[MM];

struct node{
    int i = INT_MAX;
    bool vis[2];
    node* ch[2];
    node(){}
    
    void insert(int num, int ind, int bit = (1<<29)){
        if(!bit){
            i = min(i, ind);
            return;
        }
        
        bool v = num&bit;
        
        if(!vis[v]){
            vis[v] = 1;
            ch[v] = new node();
        }
        
        ch[v]->insert(num, ind, bit>>1);
    }
};

int main(){
    
    node *rt = new node();
    
    scan(N, Q);
    for(int i = 0; i < N; i++){
        scan(a[i]);
        rt->insert(a[i], i);
    }
    
    int q = 0;
    for(int i = 0,n; i < Q; i++){
        scan(n);
        q ^= n;
        
        node *cur = rt;
        
        for(int bit = (1<<29); bit; bit>>=1){
            bool v = q&bit;
            
            if(!cur->vis[v])
                v ^= 1;
            
            cur = cur->ch[v];
        }
        
        print(cur->i);
    }
    
    return 0;
}