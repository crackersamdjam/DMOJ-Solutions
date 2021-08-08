#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

#define lc (l<<1)
#define rc (l<<1|1)

typedef int T;
typedef std::pair<int, int> pii;
constexpr int MM = 250002;

int a[MM], n, m, q;
std::priority_queue<pii> pq;

int tree[MM*2];

int query(int l, int r){
    int ret = 0;
    for(l += n, r += n+1; l < r; l >>= 1, r >>= 1){
        if(l&1)
            ret = std::max(ret, tree[l++]);
        if(r&1)
            ret = std::max(ret, tree[--r]);
    }
    return ret;
}

void update(int l, int v){
    tree[l+n] = v;
    l += n;
    for(l >>= 1; l > 0; l >>= 1){
        tree[l] = std::max(tree[lc], tree[rc]);
        tree[l] = std::max(tree[lc], tree[rc]);
    }
}


int main(){
    
    scan(n, m);
    for(int i = 1; i <= n; i++){
        scan(a[i]);
        update(i, a[i]);
        pq.emplace(a[i], i);
    }
    scan(q);
    for(int t = 0,op,i,e; t < q; t++){
        
        op = gc;
        scan(i);
        if(op == 'E'){
            scan(e);
            std::vector<pii> v;
            
            for(int j = 1; j < e; j++){
                while(pq.top().first != a[pq.top().second]){
                    pq.pop(); //old stuff delete
                }
                v.emplace_back(pq.top());
                pq.pop();
            }
            int nv = v.size() ? v.back().first : query(1, n)+1;
            
            //old
            
            a[i] = nv;
            update(i, a[i]);
            pq.emplace(a[i], i);
            
            for(auto j: v){
                j.first++;
                a[j.second] = j.first;
                update(j.second, j.first);
                pq.emplace(j);
            }
        }
        else{
            if(i == m){
                print(0);
                continue;
            }
            if(i < m){
                auto res = query(i, m-1);
                int l = m+1, mid, r = n;
                while(l <= r){
                    mid = (l+r)/2;
                    if(query(m+1, mid) < res)
                        l = mid+1;
                    else
                        r = mid-1;
                }
                print(r-i);
            }
            else{
                auto res = query(m+1, i);
                int l = 1, mid, r = m-1;
                while(l <= r){
                    mid = (l+r)/2;
                    if(query(mid, m-1) < res)
                        r = mid-1;
                    else
                        l = mid+1;
                }
                print(i-l);
            }
        }
    }
    
    return 0;
}