#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4,popcnt,abm,mmx,tune=native")

#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using ll = long long;
const int MM = 5e4+2, MN = 2e5+2;

constexpr int mod = 1e9+7;
inline void addmod(ll &a, ll b){a += b; if(a >= mod) a -= mod;}

int n, hi, q, a[MM];
ll cnt[MM][21][21], ans[MN], cntl[21], cntr[21];

struct st{
    int l, r, i;
};
st v[MN], vl[MN], vr[MN];

void go(int l, int r, int ll, int rr){
    if(ll > rr)
        return;
    if(l == r){
        for(int ii = ll; ii <= rr; ii++)
            ans[v[ii].i] = 2; //1 ele or empty
        return;
    }
    int m = (l+r)/2;
    memset(cnt[m], 0, sizeof cnt[m]);
    
    cnt[m][0][0] = 1;
    for(int i = m+1; i <= r; i++){
        memcpy(cnt[i], cnt[i-1], sizeof cnt[i-1]);
        addmod(cnt[i][a[i]][a[i]], 1);
        for(int j = 1; j <= a[i]; j++)
            for(int k = 1; k <= hi; k++)
                addmod(cnt[i][a[i]][k], cnt[i-1][j][k]);
    }
    cnt[m][a[m]][a[m]] = 1;
    for(int i = m-1; i >= l; i--){
        memcpy(cnt[i], cnt[i+1], sizeof cnt[i+1]);
        addmod(cnt[i][a[i]][a[i]], 1);
        for(int j = a[i]; j <= hi; j++)
            for(int k = 1; k <= hi; k++)
                addmod(cnt[i][a[i]][k], cnt[i+1][j][k]);
    }
    int vlr = 0, vrr = 0;
    for(int ii = ll; ii <= rr; ii++){
        st p = v[ii];
        if(p.r <= m)
            vl[vlr++] = p;
        else if(p.l > m)
            vr[vrr++] = p;
        else{
            memset(cntl, 0, sizeof cntl);
            memset(cntr, 0, sizeof cntr);
            for(int i = 0; i <= hi; i++){
                for(int k = 0; k <= hi; k++){
                    addmod(cntl[i], cnt[p.l][k][i]);
                    addmod(cntr[i], cnt[p.r][k][i]);
                }
            }
    
            for(int i = 0; i <= hi; i++){
                for(int j = 0; j <= hi; j++){
                    if(j and j < i)
                        continue;
                    ans[p.i] = (ans[p.i] + cntl[i]*cntr[j]) % mod;
                }
            }
        }
    }
    for(int i = 0; i < vlr; i++)
        v[ll+i] = vl[i];
    for(int i = 0; i < vrr; i++)
        v[ll+vlr+i] = vr[i];
    go(l, m, ll, ll+vlr-1);
    go(m+1, r, ll+vlr, ll+vlr+vrr-1);
}

int main(){
    scan(n, hi);
    for(int i = 1; i <= n; i++)
        scan(a[i]);
    
    scan(q);
    for(int i = 0,l,r; i < q; i++){
        scan(l, r);
        assert(l <= r);
        v[i] = {l, r, i};
    }
    go(1, n, 0, q-1);
    
    for(int i = 0; i < q; i++)
        print(ans[i]);
    
    return 0;
}