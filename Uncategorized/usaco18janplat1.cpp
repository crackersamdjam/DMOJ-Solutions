#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using pii = pair<int, int>;
const int MM = 1e5+2;

void init(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
    #endif
}

int n, m, dp[MM][101], last[101];
pii a[MM];
vector<pii> v;

int val(int i, int j, int k){
    return dp[j][k] + v[i].second - max(v[i].first, v[j].second);
}

int main(){
    init();
    scan(n, m);
    for(int i = 1; i <= n; i++){
        scan(a[i].first, a[i].second);
        a[i].second *= -1;
    }

    v.push_back({0, 0});//idk
    sort(a+1, a+1+n);
    int x = 0;
    for(int j = 1; j <= n; j++){
        pii i = a[j];
        i.second *= -1;
        if(i.second > x){
            x = i.second;
            v.push_back(i);
        }
        else{
            m--;
        }
    }

    m = max(m, 0);

    n = v.size()-1;
    for(int i = 1; i <= n; i++){
        for(int k = 0; k <= min(i-1, m); k++){
            for(int dif = 0; dif <= k; dif++){
                int j = i-1-dif;
                dp[i][k] = max(dp[i][k], dp[j][k-dif] + v[i].second - max(v[i].first, v[j].second));
            }
        }
    }

    print(max(dp[n][m], dp[n-1][m-1]));

    /*
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int sub = n-i;
        int k = m-sub;
        if(k >= 0)
            ans = max(ans, dp[i][k]);
    }

    print(ans);
    */
    /*
    for(int i = 1; i <= n; i++){
        printf("i %d, ", v[i].first);
        for(int k = 0; k <= m; k++){
            printf("%d ", dp[i][k]);
        }
        pc(10);
    }
    */
    return 0;
}