#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1e6+1;

int n, bit[MM], id[MM], pre[MM];
map<int, int> mp;

struct{
    int c, id, r;
} q[MM];

void update(int i, int v){
    for(; i < MM; i += i&-i)
        bit[i] += v;
}

int main(){
    
    scan(n);
    
    for(int i = 0; i < n; i++){
        q[i].c = gc;
        scan(q[i].id);
        if(q[i].c ^ 'Q'){
            scan(q[i].r);
            mp[q[i].r] = 0;
        }
    }
    
    int t = n;
    
    for(auto &x: mp)
        x.second = t--;
    
    for(int i = 0; i < n; i++){
        if(q[i].c == 'Q'){
            
            int l = 0, m, r = n;
            while(l <= r){
                m = (l+r)/2;
                int sum = 0;
                for(int j = m; j; j -= j&-j)
                    sum += bit[j];
                
                if(sum >= q[i].id)
                    r = m-1;
                else
                    l = m+1;
            }
            print(id[l]);
        }
        else{
            if(q[i].c == 'M')
                update(pre[q[i].id], -1);
            
            int v = mp[q[i].r];
            update(v, 1);
            id[v] = q[i].id;
            pre[q[i].id] = v;
        }
    }
    
    return 0;
}