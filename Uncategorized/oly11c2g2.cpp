#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int NM = 4e4+1, MM = 1e5+3;

int n, m, par[NM];
long long cost, ans = 1, mod = 1e9+7;

void find(int &x){
    while(x != par[x])
        x = par[x], par[x] = par[par[x]];
}

struct edge{
    int a, b, c;
    void p(){
        find(a);
        find(b);
        if(a > b)
            swap(a, b);
    }
    bool operator ==(const edge &o) const{
        return (a == o.a) && (b == o.b) && (c == o.c);
    }
} e[MM];

int main(){
    
    scan(n, m);
    
    for(int i = 1; i <= n; i++)
        par[i] = i;
    
    for(int i = 0; i < m; i++)
        scan(e[i].a, e[i].b, e[i].c);
    
    sort(e, e+m, [](edge x, edge y){
        return x.c < y.c;
    });
    
    for(int i = 0; i < m; i++){
        e[i].p();
        e[i+1].p();
        e[i+2].p();
        if(e[i].a == e[i].b)
            continue;
        
        if((!(e[i] == e[i+1])) && (!(e[i] == e[i+2])) && (!(e[i+1] == e[i+2])) && e[i].c == e[i+1].c && e[i].c == e[i+2].c){
            map<int, int> cnt;
            for(int t = i; t < i+3; t++){
                if(e[t].a == e[t].b)
                    goto out;
                cnt[e[t].a]++;
                cnt[e[t].b]++;
            }
            
            if(cnt.size() != 3)
                goto out;
            
            for(auto x: cnt)
                if(x.second > 2)
                    abort();
            
            ans = (ans*3)%mod;
            
            cost += 2*e[i].c; //two edges
            
            for(auto j: cnt){
                par[j.first] = par[cnt.begin()->first];
            }
            i += 2;
            continue;
        }
        
        out:;
        
        par[e[i].a] = e[i].b;
        cost += e[i].c;
        
        if(e[i] == e[i+1] && e[i] == e[i+2]){
            ans = (ans*3)%mod;
            i += 2;
        }
        else if(e[i] == e[i+1] || e[i] == e[i+2])
            ans = (ans*2)%mod;
    }
    
    print(cost, ans);
    
    return 0;
}