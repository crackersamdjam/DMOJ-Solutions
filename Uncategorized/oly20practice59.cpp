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
const int MM = 505;

bitset<MM*MM> a, e, w, no;
int n, m, k;
char s[5005];

int main(){
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < n; i++){
        scanf("%s", s);
        for(int j = 0; j < m; j++){
            a[i*m+j] = s[j] == '.';
            if(j) e[i*m+j] = 1;
            if(j < m-1) w[i*m+j] = 1;
        }
    };
    
    no = a;
    swap(e, w);
    
    scanf("%s", s);
    for(int i = 0; i < k; i++){
        if(s[i] == 'S')
            a <<= m;
        if(s[i] == 'N')
            a >>= m;
        if(s[i] == 'E')
            a = (a<<1)&w;
        if(s[i] == 'W')
            a = (a>>1)&e;
        if(s[i] == '?'){
            a = (a<<m)|(a>>m)|((a<<1)&w)|((a>>1)&e);
        }
        a &= no;
    }
    
    print(a.count());
    
//    for(int i = 0; i < n; i++){
//        for(int j = 0; j < m; j++)
//            printf("%d", a.test(i*m+j));
//        pc(10);
//    }
    
    return 0;
}