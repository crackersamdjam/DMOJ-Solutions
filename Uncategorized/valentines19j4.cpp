#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
typedef long long ll;
const int MM = 300;

ll ans, m[MM], p[MM];
int N, M;
bool no[MM][MM];

int main(){
    
    scan(N, M);
    
    for(int i = 0; i < N; i++){
        scan(m[i], p[i]);
        assert(m[i] >= 0 && m[i] <= 1000 && p[i] >= 0 && p[i] <= 1000);
    }
    
    for(int i = 0,a,b; i < M; i++){
        scan(a, b);
        assert(a != b && a > 0 && a <= 300 && b > 0 && b <= 300);
        a--, b--;
        no[a][b] = no[b][a] = 1;
    }
    
    for(int i = 0; i < N; i++){
        
        ans = max(ans, p[i]);
        
        for(int j = 0; j < N; j++){
            if(no[i][j] || i == j)
                continue;
            
            ans = max(ans, p[i] * m[j] + p[j]);
            
            for(int k = 0; k < N; k++){
                if(no[i][k] || no[j][k] || i == k || j == k)
                    continue;
                
                ans = max(ans, (p[i] * m[j] + p[j]) * m[k] + p[k]);
            }
        }
    }
    
    print(ans);
    
    return 0;
}