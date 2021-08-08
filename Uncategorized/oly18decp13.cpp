#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
const int MM = 2002;
long long ans = 0;
int N, a[MM][MM], cntx = 1, cnty = 1;
struct st{
    int a,b,c,d;
} pts[MM];
map<int,int> cx, cy;
vector<int> rx, ry;
int main(){
    scan(N);
    for(int i = 1; i <= N; i++){
        st &pt = pts[i];
        scanf("%d%d%d%d",&pt.a,&pt.b,&pt.c,&pt.d);
        if(pt.a > pt.c){
            int temp = pt.a;
            pt.a = pt.c;
            pt.c = temp;
        }
        if(pt.b > pt.d){
            int temp = pt.b;
            pt.b = pt.d;
            pt.d = temp;
        }
        cx[pt.a] = cx[pt.c] = 0;
        cy[pt.b] = cy[pt.d] = 0;
    }
    for(auto &it: cx){
        it.second = cntx++;
        rx.push_back(it.first);
    }
    for(auto &it: cy){
        it.second = cnty++;
        ry.push_back(it.first);
    }
    for(int i = 1; i <= N; i++){
        st &pt = pts[i];
        a[cx[pt.a]][cy[pt.b]]++;
        a[cx[pt.a]][cy[pt.d]]--;
        a[cx[pt.c]][cy[pt.b]]--;
        a[cx[pt.c]][cy[pt.d]]++;
        // in this case, do not add one to the ending points
        // each block represents a line, the distances in between are in map
    }
    for(int i = 1; i < cntx; i++){
        for(int j = 1; j < cnty; j++){
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
            //printf("%d ", a[i][j]);
            if(a[i][j] > 0)
                ans += (long long)(rx[i] - rx[i-1])*(ry[j] - ry[j-1]);
        }
        //printf("\n");
    }
    printf("%lld\n", ans);
    return 0;
}