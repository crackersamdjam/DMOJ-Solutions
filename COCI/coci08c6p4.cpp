#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;

vector<int> v[3];
int n, sep;
queue<int> out;

int main(){
    
    scan(n);
    
    for(int i = 0,a; i < n; i++){
        scan(a);
        v[a%3].push_back(a);
    }
    
    int a = v[0].size(), b = v[1].size(), c = v[2].size();
    
    if((b && c && !a) || (a-1 > b+c))
        return !printf("impossible\n");
    
    if(b == n || c == n){
        for(int i: v[1])
            printf("%d ", i);
        for(int i: v[2])
            printf("%d ", i);
            //.-.
        pc(10);
        return 0;
    }
    
    sep = v[0].back();
    v[0].pop_back();
    
    for(int i: v[1]){
        if(!v[0].empty()){
            out.push(v[0].back());
            v[0].pop_back();
        }
        out.push(i);
    }
    
    out.push(sep);
    
    for(int i: v[2]){
        out.push(i);
        if(!v[0].empty()){
            out.push(v[0].back());
            v[0].pop_back();
        }
    }
    
    while(!out.empty()){
        printf("%d ", out.front());
        out.pop();
    }
    
    pc(10);
    
    return 0;
}