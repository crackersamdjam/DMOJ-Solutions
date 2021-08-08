#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T> void scan(T &x){cin>>x;}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){cout<<n<<'\n';}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);cout<<' ';print(rest...);}

struct matrix{
    int n, m;
    vector<vector<ll>> a;
    matrix(int _n = 0, int _m = 0){
        n = _n, m = _m;
        a.resize(n);
        for(int i = 0; i < n; i++){
            a[i].clear();
            a[i].resize(m);
        }
    }
};

int MOD;

matrix mul(matrix ma, matrix mb){
    matrix c(ma.n, mb.m);
    for(int i = 0; i < ma.n; i++){
        for(int j = 0; j < mb.m; j++){
            ll t = 0;
            for(int k = 0; k < ma.m; k++){
                t += ma.a[i][k] * mb.a[k][j];
                if(t > MOD)
                    t = MOD;
            }
            c.a[i][j] = t;
        }
    }
    return c;
}
matrix fpow(matrix m, int exp){
    if(exp == 1)
        return m;
    matrix ret = fpow(m, exp/2);
    ret = mul(ret, ret);
    if(exp&1)
        ret = mul(ret, m);
    return ret;
}

int n, m, d, k, a, b;
struct edge{
    int a, b, c;
    bool operator<(const edge &o) const{
        return c < o.c;
    }
};
edge arr[10002];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    scan(n, m, d, k, a, b);
    MOD = k;
    
    for(int i = 0; i < m; i++)
        scan(arr[i].a, arr[i].b, arr[i].c);
    sort(arr, arr+m);
    int l = 0, mid, r = 1e9+2;
    while(l <= r){
        mid = (l+r)/2;
        matrix mat(n, n);
        for(int i = 0; i < m and arr[i].c <= mid; i++){
            mat.a[arr[i].a][arr[i].b]++;
            if(arr[i].a != arr[i].b)
                mat.a[arr[i].b][arr[i].a]++;
        }
        mat = fpow(mat, d);
        if(mat.a[a][b] < k)
            l = mid+1;
        else
            r = mid-1;
    }
    if(l > 1e9)
        l = -1;
    print(l);
    
    return 0;
}