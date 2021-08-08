#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef long long ll;
const int MM = 5e5+2;

int n, qn, ans[MM];
struct st{
    int s, m, id;
} a[MM];
deque<int> q;

int bs(int j, int k){
    ll l = -2, m, r = MM;
    while(l <= r){
        m = (l+r)/2;
        if(a[k].s + a[k].m*m > a[j].s + a[j].m*m)
            r = m-1;
        else if(a[k].s + a[k].m*m > a[j].s + a[j].m*m && a[k].id < a[j].id){
            r = m-1;
        }
        else
            l = m+1;
    }
    return l;
}

int main(){
    
    scan(n, qn);
    
    for(int i = 0; i < n; i++){
        scan(a[i].s, a[i].m);
        a[i].id = i;
    }
    
    sort(a, a+n, [](st x, st y){
        if(x.s == y.s)
            return x.id < y.id;
        return x.s > y.s;
    });
    
    for(int i = 1; i < n; i++){
        if(a[i].s == a[i-1].s && a[i].m == a[i-1].m)
            a[i].s = 0, a[i].m = 0;
    }
    
    sort(a, a+n, [](st x, st y){
        if(x.s == y.s)
            return x.id < y.id;
        return x.s > y.s;
    });
    
    for(int i = 0; i < MM; i++){
        while(q.size() > 1 && (bs(q[q.size()-2], q.back()) > bs(q.back(), i) ||
            (bs(q[q.size()-2], q.back()) == bs(q.back(), i) && a[q.back()].id > a[i].id)))
            q.pop_back();
        
        q.push_back(i);
    }
    
    for(int i = 0; i < MM; i++){
        while(q.size() > 1 && ((a[q[0]].s + a[q[0]].m*i < a[q[1]].s + a[q[1]].m*i) ||
        ((a[q[0]].s + a[q[0]].m*i == a[q[1]].s + a[q[1]].m*i && a[q[1]].id < a[q[0]].id))))
            q.pop_front();
        //need exact number, bs rounds int
        
        ans[i] = a[q[0]].id;
    }
    
    for(int i = 0,t; i < qn; i++){
        scan(t);
        print(ans[t]);
    }
    
    return 0;
}