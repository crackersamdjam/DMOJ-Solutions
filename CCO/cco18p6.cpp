#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 4100;

int n, a[MM], t;

struct op{
    int l, r;
    bool operator==(op &o)const{
        return o.l == l && o.r == r;
    }
};
vector<op> ans[2];

void flip(int l, int r){
    while(l < r){
        op cp = {l, r};
        if(!ans[t].empty() && ans[t].back() == cp)
            ans[t].pop_back();
        else
            ans[t].push_back({l, r});
        swap(a[l], a[r]);
        l++, r--;
    }
}

void go(int l, int r, int m = -1){
    if(l >= r || (m != -1 && m < l) || m > r)
        return;
    
    if(m == -1)
        m = (l+r)/2;
    
    go(l, m); go(m+1, r);
    
    if((r-l+1)%2 == 1 && a[r] < a[l]){
        flip(l, m); flip(m+1, r);
        flip(l, r);
        go(l, m); go(m+1, r);
        return;
    }
    
    int cnt = 0;
    for(int i = m+1; i <= r; i++){
        if((m-(i-m-1)) >= l && a[i] < a[m-(i-m-1)])
            cnt++;
        else
            break;
    }
    
    if(!cnt)
        return;
    
    int nl = m-cnt+1, nr = m+cnt;
    
    flip(nl, m); flip(m+1, nr);
    flip(nl, nr);
    go(l, m, nl-1); go(m+1, r, nr);
}

int main(){
    
    scan(n);
    
    for(int i = 1; i <= n; i++)
        scan(a[i]);
    
    go(1, n);
    
    t = 1;
    for(int i = 1; i <= n; i++)
        scan(a[i]);
    
    go(1, n);
    
    while(!ans[0].empty() && !ans[1].empty() && ans[0].back() == ans[1].back())
        ans[0].pop_back(), ans[1].pop_back();
    
    reverse(ans[1].begin(), ans[1].end());
    print(ans[0].size() + ans[1].size());
    for(auto i: ans[0])
        print(i.l, i.r);
    for(auto i: ans[1])
        print(i.l, i.r);
    
    /*
    for(int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    */
    
    return 0;
}
/*
5
3 4 5 1 2
1 2 3 4 5
 */