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

int v[200];

ll go(int i, string str, int l){
    if(i > 2 && v[str[i-3]] == v[str[i-1]] && v[str[i-2]] == v[str[i-1]]){
        return 0;
    }
    
    if(i == str.size())
        return l;
    
    if(str[i] == 'L')
        return go(i+1, str, 1);
    if(str[i] != '_')
        return go(i+1, str, l);
    
    ll ret = 0;
    str[i] = 'B';
    ret += go(i+1, str, 1) + 20*go(i+1, str, l);
    str[i] = 'A';
    ret += 5*go(i+1, str, l);
    return ret;
}

int main(){
    
    v['A'] = v['E'] = v['I'] = v['O'] = v['U'] = 1;
    v['_'] = 2;
    
    string str;
    cin >> str;
    
    print(go(0, str, 0));
    
    return 0;
}