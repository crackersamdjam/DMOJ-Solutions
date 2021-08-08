#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using pii = pair<int, int>;
const int MM = 1e6+5;

int n, m, k;
int ls, rs;
set<int> st[MM];

void go(int a, int b){
    if(a == n or b == 1){
        cout<<"NO\n";
        exit(0);
    }
    st[a].erase(b);
    for(int i = -1; i <= 1; i++)
        for(int j = -1; j <= 1; j++)
            if(st[a+i].count(b+j))
                go(a+i, b+j);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>k;
    for(int i = 1,a,b; i <= k; i++){
        cin>>a>>b;
        st[a].insert(b);
    }
    while(size(st[1]))
        go(1, *st[1].begin());
    
    for(int i = 1; i <= n; i++){
        if(st[i].count(m))
            go(i, m);
    }

    cout<<"YES\n";
}