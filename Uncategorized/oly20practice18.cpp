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
const int MM = 1e6+5;

struct st{
    int c, l, r;
};
vector<st> v, out;
int n, pre;
char s[MM];

int main(){
    scanf("%d %s", &n, s+1);
    for(int i = 1; i <= n; i++){
        if(s[i] == pre){
            v.back().r = i;
        }
        else{
            v.push_back({s[i], i, i});
            pre = s[i];
        }
    }
    for(int i = 0; i < v.size(); i++){
        if(i == v.size()-1 or v[i].c > v[i+1].c){
            for(int j = v[i].l; j <= v[i].r; j++){
                printf("%d ", j);
            }
        }
        else{
            out.push_back(v[i]);
        }
    }
    reverse(all(out));
    for(auto i: out){
        for(int j = i.l; j <= i.r; j++)
            printf("%d ", j);
    }
    
    return 0;
}