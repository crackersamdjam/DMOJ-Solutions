#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}

using namespace std;
const int MM = 1e5, MN = 330;

int N, Q, sz, a[MM], gp[MM], mpn[1001], cnt[MN][1001];
unordered_map<int, int> mp;
bitset<1001> mask[MN], ans;
vector<int> ava(1000);

//#define g(x) ((x)/sz)
#define g(x) (gp[x])

inline int at(int i){
    if(mp[i])
        return mp[i];
    mp[i] = ava.back();
    ava.pop_back();
    return mp[i];
}

int main(){
    
    for(int i = 1; i <= 1000; i++)
        ava[i-1] = i;
    
    scan(N, Q);
    
    sz = 310;
    
    for(int i = 0; i < N; i++){
        scan(a[i]);
        gp[i] = i/sz;
        cnt[g(i)][at(a[i])]++;
        mask[g(i)][at(a[i])] = 1;
        mpn[at(a[i])]++;
    }
    
    for(int t = 0,op,l,r; t < Q; t++){
        scan(op, l, r);
        if(op == 1){
            l--;
            int v = at(a[l]);
            
            if(!--cnt[g(l)][v])
                mask[g(l)][v] = 0;
            
            if(!--mpn[v]){
                mp[a[l]] = 0;
                ava.push_back(v);
            }
            
            a[l] = r;
            v = at(a[l]);
            mpn[v]++;
            cnt[g(l)][v]++;
            mask[g(l)].set(v, 1);
        }
        
        else{
            
            l--, r--;
            int st = g(l), ed = g(r);
            
            for(int i = l; i < min(r, (st+1)*sz); i++)
                ans[at(a[i])] = 1;
            
            for(int i = st+1; i < ed; i++)
                ans |= mask[i];
            
            for(int i = max(l, ed*sz); i <= r; i++)
                ans[at(a[i])] = 1;
            
            print(ans.count());
            ans.reset();
        }
    }
    
    return 0;
}