#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 605;

char s[MM][MM], ss[MM][MM];
int n, ans, psa[MM][MM];

void turn(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            ss[j][n-i+1] = s[i][j];
    memset(psa, 0, sizeof psa);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            s[i][j] = ss[i][j];
        }
    }
    for(int i = 1; i < MM; i++){
        for(int j = 1; j < MM; j++)
            psa[i][j] = psa[i-1][j-1] + (s[i][j] == '*');
    }
}

int main(){
//    freopen("triangles.in", "r", stdin); freopen("triangles.out", "w", stdout);
    scan(n);
    for(int i = 1; i <= n; i++){
        scanf("%s", s[i]+1);
    }
    int z=4;
    while(z--){
        turn();
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                for(int r = 1; r <= n; r++){
                    if(j-r < 1 or i+r > n)
                        break;
                    if(s[i][j-r] != '*' or s[i+r][j] != '*')
                        continue;
                    int sum = 0;
                    sum += psa[i][j+r];
                    //if(i-r-1 > 0)
                      //  sum -= psa[i-r-1][j-1];
                    if(i-r > 0)
                        sum -= psa[i-r][j]; //last one will get counted somewhere else
                    //print(i, j, r, sum);
                    ans += sum;
                }
            }
        }
    }
    
    print(ans);
    
    return 0;
}
/*

5
..*..
.*...
*...*
.....
..*..

5

prefix sum of diagonals
loop i, j centre O(n^2)
loop radius k O(n)
if two points exist on those places
the add prefix sum of opposite diagonal
 
 */