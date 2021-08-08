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

string s = "Good writing is good writing is good writing.";
string a = "Good writing is good ", b = " writing is good ", c = " is good writing.";
ll len[33];

char recur(int n, int k){
    
    if(n == 0)
        return s[k];
    
    if(k < a.size())
        return a[k];
    k -= a.size();
    if(k < len[n-1])
        return recur(n-1, k);
    k -= len[n-1];
    if(k < b.size())
        return b[k];
    k -= b.size();
    if(k < len[n-1])
        return recur(n-1, k);
    k -= len[n-1];
    
    return c[k];
}

int main(){
    
    int q, n, k;
    
    len[0] = s.size();
    for(int i = 1; i <= 30; i++){
        len[i] = len[i-1]*2+a.size()+b.size()+c.size();
    }
    
    scan(q);
    while(q--){
        scan(n, k);
        if(k > len[n]){
            pc('.');
            pc(10);
            continue;
        }
        k--;
        pc(recur(n, k));
        pc(10);
    }
    
    return 0;
}
// "Good writing is good Good writing is good writing is good writing. writing is good Good writing is good writing is good writing. is good writing."