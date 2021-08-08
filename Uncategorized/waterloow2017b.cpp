#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
const int MM = 2000 + 69;

int cnt[26][MM], N, K;
char str[MM];

int main(){
    
    scan(N, K);
    scanf("%s", str+1);
    
    for(int i = 1; i <= N; i++){
        for(int j = 0; j < 26; j++){
            cnt[j][i] = cnt[j][i-1] + (str[i] - 'a' == j);
        }
    }
    
    for(int i = 1; i + K - 1 <= N; i++){
        int left = -1, right = -1;
        for(int j = 0; j < 26; j++){
            if(cnt[j][i] == 0)
                left = j;
            if(cnt[j][N] - cnt[j][i+K-1] == 0)
                right = j;
        }
        if(left == -1 || right == -1)
            continue;
        
        for(int j = 1; j < i; j++)
            pc(left + 'a');
        for(int j = i; j <= i+K-1; j++)
            pc(str[j]);
        for(int j = i+K; j <= N; j++)
            pc(right + 'a');
        
        return 0;
    }
    
    int mn = 1e9, ltr = -1;
    for(int i = 0; i < 26; i++){
        if(cnt[i][N] < mn){
            mn = cnt[i][N];
            ltr = i;
        }
    }
    
    if(mn <= K && K <= N){
        //printf("%d %d %d\n", N, K, mn);
        //still possible
        K -= mn;
        for(int i = 1; i <= N; i++){
            if(str[i] == ltr+'a')
                pc(str[i]);
            else if(K){
                K--;
                pc(str[i]);
            }
            else
                pc(ltr+'a');
        }
        return 0;
    }
    
    puts("WRONGANSWER");
    
    return 0;
}
/*
 * cheese using only one letter before and after
 */