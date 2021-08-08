#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 2e5+2, MN = 1002;

long long ans;
int n, bit[2][MN][MN];

void up(int k, int i, int j, int v){
    for(; i < MN; i += i&-i){
        for(int jj = j; jj < MN; jj += jj&-jj)
            bit[k][i][jj] += v;
    }
}

int get(int k, int i, int j){
    int ret = 0;
    for(; i > 0; i -= i&-i){
        for(int jj = j; jj > 0; jj -= jj&-jj)
            ret += bit[k][i][jj];
    }
    return ret;
}

vector<vector<int>> a[3];

struct st{
    int op, x, l, r, pl, pr;
    //0 = update and query
    //1 = query only
    //2 = delete
    bool operator <(const st &o) const{
        if(x == o.x)
            return op < o.op;
        return x < o.x;
    }
} q[MM];
int l;

void run(){
    l = 0;
    for(auto i: a[0]){
        q[l++] = {0, i[1], i[2], i[5], i[0], i[3]};
        q[l++] = {2, i[4], i[2], i[5], i[0], i[3]};
    }
    for(auto i: a[1]){
        q[l++] = {1, i[1], i[2], i[5], i[0], i[3]};
    }
    sort(q, q+l);

    int in = 0;

    for(int j = 0; j < l; j++){
        st i = q[j];

        if(i.op == 0){
            ans += in - (get(1, i.l-1, i.pr) - get(1, i.l-1, i.pl-1))
                - (in - (get(0, i.r, i.pr) - get(0, i.r, i.pl-1)));
            up(0, i.l, i.pl, 1);
            up(1, i.r, i.pr, 1);
            in++;
        }
        else if(i.op == 1){
            ans += in - (get(1, i.l-1, i.pr) - get(1, i.l-1, i.pl-1))
                - (in - (get(0, i.r, i.pr) - get(0, i.r, i.pl-1)));
        }
        else{
            up(0, i.l, i.pl, -1);
            up(1, i.r, i.pr, -1);
            in--;
        }
        
    }
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
#endif
    
    scan(n);

    for(int i = 0,a1,a2,a3,b1,b2,b3; i < n; i++){
        scan(a1, a2, a3, b1, b2, b3);
        if(a1 > b1) swap(a1, b1);
        if(a2 > b2) swap(a2, b2);
        if(a3 > b3) swap(a3, b3);
        if(a1 == b1)
            a[0].push_back({a1, a2, a3, b1, b2, b3});
        else if(a2 == b2)
            a[1].push_back({a1, a2, a3, b1, b2, b3});
        else
            a[2].push_back({a1, a2, a3, b1, b2, b3});
    }
    
    run();
    swap(a[0], a[1]);
    swap(a[1], a[2]);
    for(int j = 0; j < 3; j++)
        for(auto &k: a[j]){
            swap(k[0], k[1]);
            swap(k[1], k[2]);
            swap(k[3], k[4]);
            swap(k[4], k[5]);
        }
    run();
    swap(a[0], a[1]);
    swap(a[1], a[2]);
    for(int j = 0; j < 3; j++)
        for(auto &k: a[j]){
            swap(k[0], k[1]);
            swap(k[1], k[2]);
            swap(k[3], k[4]);
            swap(k[4], k[5]);
        }
    run();

    print(ans);

    return 0;
}