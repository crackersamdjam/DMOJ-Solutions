#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4,popcnt,abm,mmx,tune=native")

#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

template <class T> T addMod(T a, T b, T mod) { T ret = a + b; return ret < mod ? ret : ret - mod; }
template <class T> T subMod(T a, T b, T mod) { T ret = a - b; return 0 <= ret ? ret : ret + mod; }

using T = long long;
const int MOVE = 4, HOUSE = 5, GROUP = 17, MASK = (1<<20);
const T MOD = 998244353, DIVMOD = 998243401;

void fwht(std::vector<T> &a){
    int N = int(a.size());
    for(int len = 1; len < N; len <<= 1)
        for(int i = 0; i < N; i += len << 1)
            for(int j = 0; j < len; j++){
                T u = a[i+j], v = a[len+i+j];
                a[i+j] = addMod(u, v, MOD);
                a[len+i+j] = subMod(u, v, MOD);
            }
}

std::vector<T> ans(MASK), gf(MASK);

int N, Q;
T val[MOVE];
std::vector<int> vec[GROUP];
std::map<T, T> nums;

void go(int i, int j, std::vector<int> as){
    if(j == vec[i].size()){
        int m = 0;
        int cnt[5] = {0, 0, 0, 0, 0};
        for(int k = 0; k < j; k++){
            m ^= (vec[i][k] << (as[k]*4));
            cnt[as[k]]++;
        }
        if((*std::max_element(cnt, cnt+5))*2 < as.size())
            return;
        gf[m]++;
        return;
    }
    for(int k = 0; k < HOUSE; k++){
        as[j] = k;
        go(i, j+1, as);
    }
}

int main(){
    
    scan(N, Q);
    
    for(int i = 1,k,m,cnt=0; i <= N; i++){
        cnt++;
        if(i%10 == 0)
            cnt -= 9;
        
        scan(k);
        m = 0;
        while(k--){
            int ic = gc;
            if(ic == 's')
                m |= 1, gc;
            else if(ic == 'h')
                m |= 2;
            else if(ic == 'c')
                m |= 4, gc;
            else
                m |= 8, gc;
            gc;gc;gc;gc;
        }
        vec[cnt-1].push_back(m);
    }
    
    for(int i = 0; i < MOVE; i++)
        scan(val[i]);
    
    for(int i = 0; i < GROUP; i++){
        if(vec[i].empty()) continue;
        std::vector<int> v(vec[i].size());
        go(i, 0, v);
        
        if(i){
            fwht(gf);
            for(int j = 0; j < MASK; j++)
                ans[j] = ans[j]*gf[j] % MOD;
            fill(gf.begin(), gf.end(), 0);
        }
        else{
            swap(ans, gf);
            fwht(ans);
        }
    }
    
    fwht(ans);
    for(int i = 0; i < MASK; i++)
        ans[i] = (ans[i]*DIVMOD) % MOD;
    
    for(int i = 1; i < MASK; i++){
        T v = 0;
        for(int j = 0; j < 20; j++){
            if(i&(1<<j))
                v += val[j&3];
        }
        nums[v] = addMod(nums[v], ans[i], MOD);
    }
    
    nums[-1] = 0;
    T sum = 0;
    for(auto &i: nums){
        sum = addMod(sum, i.second, MOD);
        i.second = sum;
    }
    
    int a, b;
    while(Q--){
        scan(a, b);
        T out = (--nums.upper_bound(b))->second - (--nums.lower_bound(a))->second;
        if(out < 0)
            out += MOD;
        print(out);
    }
    
    return 0;
}