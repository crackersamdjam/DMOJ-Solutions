#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}

using namespace std;
typedef long long ll;
const int MM = 2e6+2, base = 131;

ll v[MM], h[MM];
unordered_map<ll, int> dis;
int N, ans;
char str[MM];

int main(){
    
    scan(N);
 
    v[0] = 1;
    for(int i = 1; i < MM; i++)
        v[i] = v[i-1]*base;
    
    for(int t = 0; t < N; t++){
        scanf("%s", str+1);
        int n = strlen(str+1);
        
        for(int i = 1; i <= n; i++){
            h[i] = h[i-1] * base + str[i] - 'a' + 1;
        }
        
        int best = 0;
        
        for(int l = 1; l <= n; l++){
            if(h[l] != h[n] - h[n-l]*v[n-(n-l)])
                continue;
            
            best = max(best, dis[h[l]]+1);
        }
    
        dis[h[n]] = max(dis[h[n]], best);
        ans = max(ans, best);
        
    }
    
    print(ans);
    
    return 0;
}