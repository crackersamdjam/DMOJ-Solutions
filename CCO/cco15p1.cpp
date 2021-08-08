#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef long long ll;

int n;
ll w, low, h1, h2, cnt;
vector<ll> a, b, c;

int main(){
    
    scan(n, w);
    
    for(int i = 0,v; i < n; i++){
        scan(v);
        if(v == w)
            cnt++;
        else if(v < w)
            a.push_back(v);
        else
            b.push_back(v);
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<ll>());
    
    while(cnt--){
        if(a.size() < b.size())
            a.push_back(w);
        else
            b.push_back(w);
    }
    
    int z = min(a.size(), b.size());
    low = (a.size() ? (w-a[0]) : 0) + (b.size() ? (b[0]-w) : 0);
    
    if(a.size() > z)
        c.insert(c.end(), a.begin()+z, a.end());
    else if(b.size() > z)
        c.insert(c.end(), b.begin()+z, b.end());
    
    int last = w;
    for(int i = 0; i < z; i++){
        h1 += max(abs(last-a[i]), abs(w-a[i]));
        last = a[i];
        h1 += max(abs(last-b[i]), abs(w-b[i]));
        last = b[i];
    }
    
    //now do rest
    for(int i = 0,j; i <= c.size()/2; i++){
        j = c.size()-1-i;
        if(i > j) break;
        h1 += max(abs(last-c[i]), abs(w-c[i]));
        last = c[i];
        if(i >= j) break;
        h1 += max(abs(last-c[j]), abs(w-c[j]));
        last = c[j];
    }
    
    last = w;
    for(int i = 0; i < z; i++){
        h2 += max(abs(last-b[i]), abs(w-b[i]));
        last = b[i];
        h2 += max(abs(last-a[i]), abs(w-a[i]));
        last = a[i];
    }
    
    //now do rest
    for(int i = 0,j; i <= c.size()/2; i++){
        j = c.size()-1-i;
        if(i > j) break;
        h2 += max(abs(last-c[i]), abs(w-c[i]));
        last = c[i];
        if(i >= j) break;
        h2 += max(abs(last-c[j]), abs(w-c[j]));
        last = c[j];
    }
    
    print(low, max(h1, h2));
    
    return 0;
}