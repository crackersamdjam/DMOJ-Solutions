#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
using ld = long double;
const int MM = 1e5+2;

int n, m, pre[201][MM], l, r, nl, nr;
ll dp[2][MM], ps[MM], q[MM], nq[MM];
vector<int> ans;

ll sq(ll x){ return x*x;}

ld eq(int j, int k, int lv){
    return ld(dp[lv][j] - dp[lv][k] + sq(ps[k]) - sq(ps[j]))/ld(ps[k] - ps[j]);
}

int main(){
    
    scan(n, m);
    
    for(int i = 1; i <= n; i++){
        scan(ps[i]);
        ps[i] += ps[i-1];
    }
    
    for(int t = 0; t <= m; t++){
        l = nl, r = nr; nl = 0, nr = -1; swap(q, nq); swap(dp[0], dp[1]);
        for(int i = 1; i <= n; i++){
            while(r-l+1 >= 2 && q[l+1] < i && eq(q[l], q[l+1], 0) <= ps[i])
                l++;
            
            dp[1][i] = dp[0][q[l]] + ps[q[l]]*(ps[i] - ps[q[l]]);
            pre[t][i] = q[l];
            
            //cout << dp[1][i] << ' ' << l << ' ' << q[l] << ' ' << r << ", ";
            if(i > 1 && ps[i] == ps[i-1]) continue;
            
            while(nr-nl+1 >= 2 && eq(nq[nr-1], nq[nr], 1) > eq(nq[nr], i, 1))
                nr--;
            
            nq[++nr] = i;
        }
        //pc(10);
    }
    
    print(dp[1][n]);
    
    int u = n;
    for(int i = m; i > 0; i--){
        u = pre[i][u];
        ans.push_back(u);
    }
    sort(ans.begin(), ans.end());
    ans[0] = max(ans[0], 1);
    for(int i = 1; i < ans.size(); i++)
        ans[i] = max(ans[i], ans[i-1]+1);
    for(int i: ans)
        printn(i), pc(32);
    
    return 0;
}

/*
 dp[i][n] = dp[j][n-1] + ps[j]*(ps[i]-ps[j]); j < i
 dp[j] + ps[j]*ps[i] - ps[j]^2 <= dp[k] + ps[k]*ps[i] - ps[k]^2   ; j < k
 dp[k] + ps[k]*ps[i] - ps[k]^2 >= dp[j] + ps[j]*ps[i] - ps[j]^2
 ps[k]*ps[i] - ps[j]*ps[i]  >= dp[j] - dp[k] + ps[k]^2 - ps[j]^2
 ps[i]*(ps[k] - ps[j]) >= dp[j] - dp[k] + ps[k]^2 - ps[j]^2
 ps[i] >= (dp[j] - dp[k] + ps[k]^2 - ps[j]^2)/(ps[k] - ps[j])

 */
/*
7 3
4 1 3 4 0 2 3
0 0 0 0 0 0 0
0 4 16 35 35 48 72
0 4 19 48 48 64 95
0 4 19 51 51 72 108
108
1 3 5
 */