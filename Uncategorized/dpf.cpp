#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
const int MM = 3002;

int dp[MM][MM];
char a[MM], b[MM], c[MM];

int main(){
    
    scanf("%s %s", a+1, b+1);
    int n = strlen(a+1), m = strlen(b+1);
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1]+1;
            
            dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
        }
    }
    int ptr = MM-1;
    c[ptr] = '\0';
    for(int i = n, j = m; i > 0 && j > 0;){
        if(a[i] == b[j]){
            c[--ptr] = a[i];
            i--, j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }
    printf("%s", c+ptr);
    
    return 0;
}