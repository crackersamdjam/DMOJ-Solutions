#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 2e5+2;

int n, m, t, a[MM*3], bit[MM], ans[MM], t2;
struct st{
    //0 delete, 1 insert, 2 query
    int op, a, b, k, id;
};
vector<st> q;

void up(int i, int v){
    for(; i < MM; i += i&-i)
        bit[i] += v;
}

int qu(int i){
    int r = 0;
    for(; i; i -= i&-i)
        r += bit[i];
    return r;
}

void go(vector<st> &qr, int lo, int hi){
    
    if(qr.empty())
        return;
    
    if(lo == hi){
        for(int i = 0; i < qr.size(); i++){
            if(qr[i].op == 2){
                ans[qr[i].id] = lo;
                //printf("ans "); print(qr[i].id, lo);
            }
        }
        return;
    }
    
    vector<st> lc, rc;
    int mid = (lo+hi)/2;
    
    for(int i = 0; i < qr.size(); i++){
        
        if(qr[i].op == 0){
            if(qr[i].b <= mid){
                up(qr[i].a, -1);
                lc.push_back(qr[i]);
            }
            else
                rc.push_back(qr[i]);
        }
        
        if(qr[i].op == 1){
            if(qr[i].b <= mid){
                //index
                //printf("up "); print(qr[i].a, qr[i].b, mid);
                up(qr[i].a, 1);
                a[qr[i].a] = qr[i].b;
                lc.push_back(qr[i]);
            }
            else
                rc.push_back(qr[i]);
        }
        
        if(qr[i].op == 2){
            int cnt = qu(qr[i].b) - qu(qr[i].a-1);
            //print(qr[i].id, cnt, qr[i].k, mid);
            if(cnt >= qr[i].k)
                lc.push_back(qr[i]);
            else{
                qr[i].k -= cnt;
                rc.push_back(qr[i]);
            }
        }
    }
    
    for(int i = 0; i < qr.size(); i++){
        if(qr[i].op == 0 && qr[i].b <= mid)
            up(qr[i].a, 1);
        if(qr[i].op == 1 && qr[i].b <= mid)
            up(qr[i].a, -1);
    }
    
    go(lc, lo, mid);
    go(rc, mid+1, hi);
}

int main(){
    
    scan(n);
    
    for(int i = 1; i <= n; i++){
        scan(a[i]);
        q.push_back({1, i, a[i]});
        //insert a[i] at i
    }
    
    scan(m);
    
    for(int i = 0,op,b,c,d; i < m; i++){
        scan(op, b, c);
        if(op == 1){
            q.push_back({0, b, a[b]});
            q.push_back({1, b, a[b] = c});
        }
        else{
            scan(d);
            q.push_back({2, b, c, d, t2++});
        }
    }
    
    go(q, 1, 1e9);
    
    for(int i = 0; i < t2; i++)
        print(ans[i]);
    
    return 0;
}