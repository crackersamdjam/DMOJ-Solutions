#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;

int n, st, ans;
string a;
vector<int> g, s, p;

int main(){
    
    cin >> n >> a;
    for(int i = 1; i < n; i++){
        if(a[i] != a[i-1])
            st = i;
    }
    a = a.substr(st) + a.substr(0, st);
    
    //cout << a << '\n';
    
    for(int i = 0; i < n; i++){
        if(a[i] == 'g')
            g.push_back(i);
        if(a[i] == 's')
            s.push_back(i);
        if(a[i] == 'p')
            p.push_back(i);
    }
    //cout << a << '\n';
    
    if(g.size() <= 1 || s.size() <= 1){
        print(n);
        return 0;
    }
    
    for(int i = 0; i < n; i++){
        if(a[i] != 's' and a[i+1] != 'g' && (i == n or a[i] != a[i+1])){
            //gggsss
            int pre;
            if(s[0] > i){
                pre = s.back() - n;
            }
            else{
                pre = *--lower_bound(s.begin(), s.end(), i);
            }
            
            int nx;
            if(g.back() < i+1){
                nx = n + g[0];
            }
            else{
                nx = *lower_bound(g.begin(), g.end(), i+1);
            }
            nx--;
            
            ans = max(ans, nx - pre);
            //print(pre, i, nx);
        }
    }
    reverse(a.begin(), a.end());
    g.clear();s.clear();p.clear();
    for(int i = 0; i < n; i++){
        if(a[i] == 'g')
            g.push_back(i);
        if(a[i] == 's')
            s.push_back(i);
        if(a[i] == 'p')
            p.push_back(i);
    }
    for(int i = 0; i < n; i++){
        if(a[i] != 's' and a[i+1] != 'g' && (i == n or a[i] != a[i+1])){
            //gggsss
            int pre;
            if(s[0] > i){
                pre = s.back() - n;
            }
            else{
                pre = *--lower_bound(s.begin(), s.end(), i);
            }
            
            int nx;
            if(g.back() < i+1){
                nx = n + g[0];
            }
            else{
                nx = *lower_bound(g.begin(), g.end(), i+1);
            }
            nx--;
            
            ans = max(ans, nx - pre);
            //print(pre, i, nx);
        }
    }
    
    print(min(ans, n));
    
    return 0;
}