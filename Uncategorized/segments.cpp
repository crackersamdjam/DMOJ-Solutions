#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

#define lc (rt<<1)
#define rc (rt<<1|1)
#define m ((nl+nr)>>1)

using namespace std;
const int MM = 2e5+1;

int T, N;
map<int, int> mp;
priority_queue<int, vector<int>, greater<int>> out;

struct st{
    int l, r;
} a[MM];

struct node{
    int val, lp;
} tree[MM*3];

inline void push_up(int rt){
    tree[rt].val = max(tree[lc].val, tree[rc].val);
}

inline void push_down(int rt, int nl, int nr){
    int &val = tree[rt].lp;
    if(val && nl^nr){
        tree[lc].lp += val;
        tree[lc].val += val;
        tree[rc].lp += val;
        tree[rc].val += val;
    }
    val = 0;
}

void update(int l, int r, int val, int nl = 1, int nr = MM-1, int rt = 1){
    if(r < nl || l > nr)
        return;
    if(l <= nl && r >= nr){
        tree[rt].val += val;
        tree[rt].lp += val;
        return;
    }
    push_down(rt, nl, nr);
    update(l, r, val, nl, m, lc);
    update(l, r, val, m+1, nr, rc);
    push_up(rt);
}

inline int query(){
    return tree[1].val;
}

int main(){
    
    scan(T);
    
    for(int tc = 1; tc <= T; tc++){
        
        int ans = 0;
        memset(tree, 0, sizeof tree);
        while(!out.empty())
            out.pop();
        mp.clear();
        
        scan(N);
        
        for(int i = 0; i < N; i++){
            scan(a[i].l, a[i].r);
            mp[a[i].l] = mp[a[i].r] = 0;
        }
        
        int t = 0;
        for(auto &itr: mp)
            itr.second = ++t;
        
        for(int i = 0; i < N; i++){
            a[i].l = mp[a[i].l], a[i].r = mp[a[i].r];
            update(a[i].l, a[i].r, 1);
        }
        
        sort(a, a+N, [](const st &x, const st &y){
            return x.l < y.l;
        });
        
        for(int i = 1, touch = 0, l = 0; i <= t; i++){
            
            while(!out.empty() and out.top() < i){
                out.pop();
                touch--;
            }
            while(l < N and a[l].l <= i){
                update(a[l].l, a[l].r, -1);
                out.push(a[l].r);
                touch++;
                l++;
            }
            ans = max(ans, touch + query());
        }
        
        pc('C');
        pc('a');
        pc('s');
        pc('e');
        pc(32);
        print(tc);
        pc(':');
        pc(32);
        print(ans);
        pc(10);
    }
    
    return 0;
}