#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 2e6+6;

int r[MM], t = 10;
char s[MM];

int main(){
    
    while(t--){
        memset(r, 0, sizeof r);
        
        scanf("%s", s+1);
        int n = strlen(s+1), m = n*2+1;
    
        for(int i = m; i; i--){
            if(i&1)
                s[i] = s[i>>1];
            else
                s[i] = '#';
        }
        s[1] = '@';
        s[m+1] = '#';
    
        for(int i = 1, mx = 0, p = 0; i <= m; i++){
            //cout<<i<<' '<<s[i]<<'\n';
            if(i >= mx)
                r[i] = 1;
            else
                r[i] = min(mx-i, r[p*2-i]);
            while(s[i-r[i]] == s[i+r[i]])
                r[i]++;
            if(i + r[i] > mx)
                mx = i + r[i], p = i;
        }
        int v = 0;
        for(int i = 2; i <= m; i++){
            //pc(s[i]);
            r[i]--;
            if(i-r[i] == 2 or i+r[i] == m+1)
                v = max(v, r[i]);
        }
//        for(int i =2;i<=m;i++)
//            pc(s[i]);

        print(n-v);
    }
    
    return 0;
}