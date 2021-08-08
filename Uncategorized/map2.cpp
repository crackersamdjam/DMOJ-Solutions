#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

using namespace std;
const int MM = 1e6+1;

int N, Q, M, a[MM], cnt[10][MM];

int main(){
    
    scan(N, Q, M);
    M *= 10;
    
    for(int i = 0; i < N; i++){
        scan(a[i]);
        string str = to_string(a[i]);
        for(int j = 0; j < 10; j++){
            if(str.find(to_string(j)) != -1){
                cnt[j][a[i] % M] += a[i];
                //printf("%d %d %d\n", a[i], j, a[i]%M);
            }
        }
    }
    
    for(int i = 0,k,t; i < Q; i++){
        scan(k, t);
        print(cnt[t][k % M]);
    }
    
    return 0;
}