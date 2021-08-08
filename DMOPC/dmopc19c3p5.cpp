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

using std::min, std::max;
using ll = long long;
const int MM = 3e5+1, MN = 6e5+9, LIM = 1;
ll adj, acc;
//2e5 range

int n, q;
ll a[MM];
ll cnt[LIM][LIM], temp[LIM], cur[LIM];
int bit[MN];
ll sum[MN];
ll maxv = LLONG_MIN, minv = LLONG_MAX;

void up(ll i, ll v){
    for(i = max(min(i-adj+3, MN-1LL), 1LL); i < MN; i += i&-i)
        bit[i]++, sum[i] += v;
}

std::pair<int, ll> qu(ll i){
    int c = 0; ll r = 0;
    for(i = max(min(i-adj+3, MN-1LL), 0LL); i > 0; i -= i&-i)
        c += bit[i], r += sum[i];
    return {c, r};
}

int main(){
    
    scan(n, q);
    
    for(int i = 1; i <= n; i++){
        scan(a[i]);
        maxv = max(maxv, a[i]);
        minv = min(minv, a[i]);
        for(int j = 1; j < LIM; j++){
            ll v = a[i]%j;
            if(v < 0) v += j;
            cnt[j][v]++;
        }
    }
    minv -= 2e5;
    maxv += 2e5;
    adj = minv;
    for(int i = 1; i <= n; i++)
        up(a[i], a[i]);
    
    for(int z = 0,op; z < q; z++){
        ll k; scan(op, k);
        if(op == 1){
            k -= acc;
            for(int j = 1; j < LIM; j++){
                ll v = (k+cur[j])%j;
                if(v < 0) v += j;
                cnt[j][v]++;
            }
            up(k, k);
        }
        else if(op == 2){
            acc += k;
        }else{
            if(k < LIM){
                
                ll sh = (acc-cur[k])%k;
                if(sh < 0) sh += k;
                if(sh){
                    for(int i = 0; i < k; i++)
                        temp[i] = cnt[k][(i-sh) < 0 ? i-sh+k : i-sh];
                    for(int i = 0; i < k; i++)
                        cnt[k][i] = temp[i];
                    cur[k] = acc;
                }
                
                ll ans = 0;
                for(ll i = 0; i < k; i++)
                    ans += cnt[k][i]*min(i, k-i);
                print(ans);
                continue;
            }
            ll ans = 0, half = k/2, sh = (minv/k)*k - acc%k;
            while(sh >= minv) sh -= k;
            for(; sh <= maxv; sh += k){
                auto f = qu(sh), s = qu(sh+half);
                ans += (s.second - f.second) - sh*(s.first - f.first);
                f = qu(sh+half), s = qu(sh+k);
                ans += (sh+k)*(s.first - f.first) - (s.second - f.second);
            }
            print(ans);
        }
    }
    
    /*
    //subtask 1 brute force
    for(int i = 0; i < n; i++){
        ll b; scan(b);
        nums.push_back(b);
    }
    for(int z = 0,op; z < q; z++){
        ll k; scan(op, k);
        if(op == 1){
            nums.push_back(k);
        }
        else if(op == 2){
            for(ll &i: nums)
                i += k;
        }
        else{
            ll ans = 0;
            for(ll i: nums){
                ll v = i%k;
                if(v < 0) v += k;
                ans += min(v, k-v);
            }
            print(ans);
        }
    }
     */
    
    return 0;
}
/*
 * since k is increasing, worst case is harmonic series
 * no need to maintain cnt array for k < LIM
 * 
 */