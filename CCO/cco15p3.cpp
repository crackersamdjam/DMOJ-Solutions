#define ONLINE_JUDGE

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
using pii = pair<int, int>;
const int MM = 2002, MN = 800002;

struct sparse_table{
    int n; ll sp[12][MM];
    vector<ld> vec;
    ll query(int a, int b){
        a = upper_bound(vec.begin(), vec.end(), a) - 1 - vec.begin(); //take last value
        b = upper_bound(vec.begin(), vec.end(), b) - 1 - vec.begin();
        int k = 31-__builtin_clz(b-a+1);
        return max(sp[k][a], sp[k][b-(1<<k)+1]);
    }
    void build(int _n){
        n = _n;
        for(int k = 1; k <= 31-__builtin_clz(n+1); k++)
            for(int i = 0; i+(1<<k) <= n; i++)
                sp[k][i] = max(sp[k-1][i], sp[k-1][i+(1<<(k-1))]);
    }
    void clear(){
        memset(sp, 0, sizeof sp);
        vec.clear();
    }
} rmq;

int x, k, n, q, a[MM], b[MM], c[MM];
vector<pair<ld, ll>> dif[MM];
// x, value
map<int, ll, greater<int>> mp;
ll ans[MN];
vector<pii> qu[MM];

int main(){
    
    scan(x, k, n, q);
    
    for(int i = 0; i < n; i++){
        scan(a[i], b[i], c[i]);
        mp[a[i]] += c[i];
    }
    
    ll sum = 0;
    for(auto &i: mp){
        sum += i.second;
        i.second = sum-i.second;
    }
    
    for(int i = 0; i < n; i++)
        dif[i].emplace_back(0, mp[a[i]]);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            ld inter = ld(a[j]-a[i])*x/(b[i]-a[i]-b[j]+a[j]);
            if(inter >= x || inter <= 0) continue;
            //i overtakes j
            if(a[i] > a[j]){
                dif[j].emplace_back(inter, -c[i]);
                dif[i].emplace_back(inter, c[j]);
            }
            else{
                dif[j].emplace_back(inter, c[i]);
                dif[i].emplace_back(inter, -c[j]);
            }
        }
    }
    
    for(int i = 0,l,s; i < q; i++){
        scan(l, s);
        qu[l-1].emplace_back(s, i);
    }
    
    for(int i = 0; i < n; i++){
        sort(dif[i].begin(), dif[i].end());
        rmq.clear();
        int nj = 0;
        for(int j = 0; j < dif[i].size(); j++){
            if(j) dif[i][j].second += dif[i][j-1].second;
            if(j < dif[i].size()-1 && dif[i][j].first == dif[i][j+1].first)
                continue;
            rmq.sp[0][nj] = dif[i][j].second;
            rmq.vec.emplace_back(dif[i][j].first);
            nj++;
        }
        rmq.build(dif[i].size());
        for(auto p: qu[i]){
            ans[p.second] = rmq.query(p.first, p.first+k);
        }
    }
    
    for(int i = 0; i < q; i++)
        print(ans[i]);
    
    return 0;
}