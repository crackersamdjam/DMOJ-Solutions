#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 4008;

int l, t, bit[MM][MM], cnt;
bool b[MM][MM];

void update(int i, int jj, int v){
    for(; i < MM; i += i&-i){
        for(int j = jj; j < MM; j += j&-j)
            bit[i][j] += v;
    }
}

int query(int i, int jj){
    static int ret;
    for(ret = 0; i; i -= i&-i){
        for(int j = jj; j; j -= j&-j)
            ret += bit[i][j];
    }
    return ret;
}

int main(){
    
    scan(l, t);
    
    int op, ir, ic, r, c;
    while(t--){
        op = gc; scan(ir, ic);
        
        if(ir > 2000)
            continue;
        
        r = 1002+ir-ic;
        c = ir+ic;
        
        if(op == 'E'){
            update(r, c, 1);
            b[r][c] = 1;
            cnt++;
        }
        else if(op == 'L'){
            update(r, c, -1);
            b[r][c] = 0;
            cnt--;
        }
        else{
            assert(op == 'S');
            if(b[r][c] || b[r-1][c+1])
                puts("No");
            else
                print(query(r, c) + query(r-1, c+1));
        }
    }
    
    int fs = 1e9, sd = 1e9, v;
    for(ir = l+1; ir < 2002; ir++){
        for(ic = 1; ic <= 1000; ic++){
            r = 1002+ir-ic;
            c = ir+ic;
            if(b[r][c])
                continue;
            v = query(r, c);
            if(v < fs)
                fs = v;
            else if(v < sd)
                sd = v;
        }
    }
    print(fs + sd);
    
    return 0;
}