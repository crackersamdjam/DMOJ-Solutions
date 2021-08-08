#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

using namespace std;
const int MM = 4e5+1;

int N, A, C, cnt, ans, t[2][MM], r[MM];
struct{
    int l, r;
} a[MM], c[MM];

map<int, int> mp;

int main(){
    
    scan(N, A, C);
    
    for(int i = 0; i < A; i++){
        scan(a[i].l, a[i].r);
        mp[a[i].l] = mp[++a[i].r] = 0;
    }
    
    
    for(int i = 0; i < C; i++){
        scan(c[i].l, c[i].r);
        mp[c[i].l] = mp[++c[i].r] = 0;
    }
    
    for(auto &it: mp){
        it.second = ++cnt;
        r[cnt] = it.first;
    }
    
    for(int i = 0; i < A; i++){
        t[0][mp[a[i].l]]++;
        t[0][mp[a[i].r]]--;
    }
    
    for(int i = 0; i < C; i++){
        t[1][mp[c[i].l]]++;
        t[1][mp[c[i].r]]--;
    }
    
    for(int i = 1; i < cnt; i++){
        
        t[0][i] += t[0][i-1];
        t[1][i] += t[1][i-1];
        
        if(t[0][i] and !t[1][i])
            ans += r[i+1] - r[i];
    }
    
    print(ans);
    
    return 0;
}