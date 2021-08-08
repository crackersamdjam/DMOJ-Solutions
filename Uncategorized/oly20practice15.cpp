#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 3003;

int n, m;
char s[MM][MM];
int last, pre[3], dp[3];
vector<pair<int, int>> v;

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++){
        scanf("%s", s[i]+1);
        for(int j = 1; j <= m; j++)
            v.emplace_back(i+j, i);
    }
    sort(v.begin(), v.end());
    for(auto p: v){
        int i = p.second, j = p.first-i;
        dp[0] = *max_element(pre, pre+3);
        if(s[i][j-1] == 'R' and s[i][j] == 'G' and s[i][j+1] == 'W'){
            if(last == i+j){
                dp[1] = max(pre[0], pre[1]) + 1;
            }
            else{
                dp[1] = dp[0]+1;
            }
        }
        if(s[i-1][j] == 'R' and s[i][j] == 'G' and s[i+1][j] == 'W'){
            if(last == i+j){
                dp[2] = max(pre[0], pre[2]) + 1;
            }
            else{
                dp[2] = dp[0]+1;
            }
        }
        last = i+j;
        pre[0] = dp[0], pre[1] = dp[1], pre[2] = dp[2];
    }
    
    print(*max_element(dp, dp+3));
    
    return 0;
}