#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
const int MM = 3e5+5;
const ll mod = 1e9+7;

struct matrix{
    int n, m;
    vector<vector<ll>> a;
    matrix(int _n = 0, int _m = 0){
        n = _n, m = _m;
        a.resize(n);
        for(auto &i: a){
            i.resize(m);
            for(auto &j: i)
                j = 0;
        }
    }
};
matrix mult(matrix a, matrix b){
    matrix c(a.n, b.m);
    for(int i = 0; i < a.n; i++){
        for(int j = 0; j < b.m; j++){
            ll t = 0;
            for(int k = 0; k < a.m; k++)
                t = (t + a.a[i][k]*b.a[k][j]) % mod;
            c.a[i][j] = (t%mod+mod)%mod;
        }
    }
    return c;
}

matrix psa[MM], inv[MM];
int n, q, a[MM];

int main(){
    scan(n, q);
    for(int i = 1; i <= n; i++)
        scan(a[i]);
    psa[0] = matrix(2, 2);
    psa[0].a = {{1, 0}, {0, 1}};
    inv[0] = psa[0];

    for(int i = 1; i <= n; i++){
        // matrix tt(2, 1);
        // tt.a = {{a[i]}, {1}};

        psa[i] = matrix(2, 2);
        psa[i].a = {{a[i], 1}, {1, 0}};
        psa[i] = mult(psa[i-1], psa[i]);

        // matrix tmp = mult(psa[i-1], tt);
        // print(i, tmp.a[0][0], tmp.a[1][0]);

        // printf("psa\n");
        // print(psa[i].a[0][0], psa[i].a[0][1]);
        // print(psa[i].a[1][0], psa[i].a[1][1]);

        inv[i] = matrix(2, 2);
        inv[i].a = {{0, 1}, {1, -a[i]}};
        inv[i] = mult(inv[i], inv[i-1]); //other way around

        // printf("inv\n");
        // print(inv[i].a[0][0], inv[i].a[0][1]);
        // print(inv[i].a[1][0], inv[i].a[1][1]);

        // tmp = mult(inv[i], psa[i]);
        // printf("both\n");
        // print(tmp.a[0][0], tmp.a[0][1]);
        // print(tmp.a[1][0], tmp.a[1][1]);
    }

    while(q--){
        int l, r;
        scan(l, r);
        matrix tt(2, 1);
        tt.a = {{a[r]}, {1}};
        matrix res = mult(mult(inv[l-1], psa[r-1]), tt);
        print(res.a[0][0], res.a[1][0]);
    }
    
    return 0;
}