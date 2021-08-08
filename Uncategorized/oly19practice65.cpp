#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1e6;

int n, q, id[MM], l[MM], r[MM], a[MM], b[MM], sz[MM], ans[MM];
map<int, int> mp, pos;
vector<pair<int, int>> ql, qp;
vector<int> v;

int main(){
    
    scan(n);
    
    for(int i = 0; i < n; i++){
        scan(a[i], b[i]);
        mp[a[i]] = mp[a[i]+1] = mp[b[i]] = mp[b[i]+1] = mp[a[i]-1] = mp[b[i]-1] = 0;
    }
    
    scan(q);
    
    for(int i = 0,op,x; i < q; i++){
        op = gc == 'L';
        scan(x);
        if(op)
            ql.push_back({x, i});
        else{
            mp[x] = 0;
            qp.push_back({x, i});
        }
    }
    
    mp[0] = mp[1e9+2] = 0;
    int pre = 0, t = 0;
    for(auto &i: mp){
        i.second = t;
        sz[t] = i.first - pre;
        pre = i.first;
        v.push_back(i.first);
        t++;
    }
    
    for(int i = 0; i < t; i++)
        id[i] = v[i], l[i] = i-1, r[i] = i+1;
    
    for(int i = 0; i < n; i++){
        a[i] = mp[a[i]], b[i] = mp[b[i]];
        if(a[i] == l[b[i]])
            continue;
        
        int t1 = l[a[i]], t2 = r[a[i]], t3 = r[a[i]], t31 = l[a[i]], t4 = l[b[i]];
        int nl = l[b[i]], nr = b[i];
        r[t1] = t2, l[t3] = t31;
        r[t4] = a[i], l[b[i]] = a[i];
        l[a[i]] = nl, r[a[i]] = nr;
    }
    
    sort(ql.begin(), ql.end());
    int ptr = 0, cur = 0, cnt = 0;
    for(int i = 0; i < t-1; i++){
        cnt += sz[cur];
        pos[id[cur]] = cnt;
        
        while(ptr < ql.size() and (cnt + sz[r[cur]] > ql[ptr].first)){
            ans[ql[ptr].second] = id[cur] + (ql[ptr].first - cnt);
            ptr++;
        }
        cur = r[cur];
    }
    
    for(auto i: qp)
        ans[i.second] = pos[i.first];
    
    for(int i = 0; i < q; i++)
        print(ans[i]);
    
    return 0;
}