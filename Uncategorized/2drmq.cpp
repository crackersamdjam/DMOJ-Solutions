// :wesleycreep:
// reeeeeeeeeeeeeeeeeeeeeeeeeejudge
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4,popcnt,abm,mmx,tune=native")

#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T MM){bool _=0;_=MM<0;MM=_?-MM:MM;char snum[65];int i=0;do{snum[i++]=MM%10+48;MM/= 10;}while(MM);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T MM){printn(MM);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}
#endif

const int MM = 1000, LOG = 10;

int SP[LOG][LOG][MM][MM];

inline int min(int a, int b){
    return (a < b) ? a : b;
}

void init(std::vector<std::vector<int>> arr){
    int N = arr.size();
    for (int jr = 0; jr < N; jr++) for (int jc = 0; jc < N; jc++) SP[0][0][jr][jc] = arr[jr][jc];
    for (int ic = 0; ic < LOG - 1; ic++) for (int jr = 0; jr < N; jr++) for (int jc = 0; jc < N; jc++)
        SP[0][ic + 1][jr][jc] = min(SP[0][ic][jr][jc], SP[0][ic][jr][min(jc + (1 << ic), N - 1)]);
    for (int ir = 0; ir < LOG - 1; ir++) for (int ic = 0; ic < LOG; ic++) for (int jr = 0; jr < N; jr++) for (int jc = 0; jc < N; jc++)
        SP[ir + 1][ic][jr][jc] = min(SP[ir][ic][jr][jc], SP[ir][ic][min(jr + (1 << ir), N - 1)][jc]);
        
    }

int query(int u, int d, int l, int r){
    int ir = 31 - __builtin_clz(d - u + 1), ic = 31 - __builtin_clz(r - l + 1);
    return min(min(SP[ir][ic][u][l], SP[ir][ic][d - (1 << ir) + 1][r - (1 << ic) + 1]),
               min(SP[ir][ic][d - (1 << ir) + 1][l], SP[ir][ic][u][r - (1 << ic) + 1]));
}

#ifndef ONLINE_JUDGE
int main(){
    init({{1, 2}, {3, 4}});
    print(query(0, 1, 0, 1));
    print(query(1, 1, 0, 1));
    print(query(0, 0, 1, 1));
}
#endif