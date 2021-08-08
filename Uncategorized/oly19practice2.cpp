#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#define _CRT_SECURE_NO_WARNINGS
#endif
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
typedef long long ll;
const int MM = 50001;

int N, leftmax[MM], leftmin[MM], rightmax[MM], rightmin[MM];

struct point{
    int x, y;
} a[MM];

int main(){
    
    scan(N);
    
    for(int i = 1; i <= N; i++){
        scan(a[i].x, a[i].y);
    }
    
    sort(a+1, a+N+1, [](point &x, point &y){return x.x < y.x;});
    
    leftmax[0] = 0;
    leftmin[0] = 1e9;
    for(int i = 1; i <= N; i++){
        leftmax[i] = max(leftmax[i-1], a[i].y);
        leftmin[i] = min(leftmin[i-1], a[i].y);
    }
    
    rightmax[N+1] = 0;
    rightmin[N+1] = 1e9;
    for(int i = N; i > 0; i--){
        rightmax[i] = max(rightmax[i+1], a[i].y);
        rightmin[i] = min(rightmin[i+1], a[i].y);
    }
    
    ll best = 1e18, def = 0;
    
    for(int i = 1; i <= N; i++){
        //cannot have boundaries overlap
        if(a[i].x == a[i+1].x){
            continue;
        }
        
        //from 1 - i, from i+1 - N
        int leftwidth = a[i].x - a[1].x, rightwidth = a[N].x - a[i+1].x;
        int leftheight = leftmax[i] - leftmin[i];
        int rightheight = rightmax[i+1] - rightmin[i+1];
        
        if(i == N){
            rightheight = rightwidth = 0;
        }
        
        ll area = (ll)leftwidth * leftheight + (ll)rightwidth * rightheight;
        
        best = min(best, area);
        
        if(i == N)
            def = area;
    }
    
    //swap
    for(int i = 1; i <= N; i++){
        int temp = a[i].x;
        a[i].x = a[i].y;
        a[i].y = temp;
    }
    
    sort(a+1, a+N+1, [](point &x, point &y){return x.x < y.x;});
    
    leftmax[0] = 0;
    leftmin[0] = 1e9;
    for(int i = 1; i <= N; i++){
        leftmax[i] = max(leftmax[i-1], a[i].y);
        leftmin[i] = min(leftmin[i-1], a[i].y);
    }
    
    rightmax[N+1] = 0;
    rightmin[N+1] = 1e9;
    for(int i = N; i > 0; i--){
        rightmax[i] = max(rightmax[i+1], a[i].y);
        rightmin[i] = min(rightmin[i+1], a[i].y);
    }
    
    for(int i = 1; i <= N; i++){
        if(a[i].x == a[i+1].x){
            continue;
        }
        
        int leftwidth = a[i].x - a[1].x, rightwidth = a[N].x - a[i+1].x;
        int leftheight = leftmax[i] - leftmin[i];
        int rightheight = rightmax[i+1] - rightmin[i+1];
        
        if(i == N){
            rightheight = rightwidth = 0;
        }
        
        ll area = (ll)leftwidth * leftheight + (ll)rightwidth * rightheight;
        
        best = min(best, area);
        
        //if(i == N)
          //  def = area;
    }
    
    print(def - best);
    
    return 0;
}
/*
 *
 * sort by x
 *
 * select point to partition
 * P[i] - P[n] is one rectangle
 * P[0] - P[i-1] is the other
 *
 * O(1) prefix max/min, suffix max/min
 *
 * left max, min
 * right max, min
 
 5 -2 8 4 -6 17 8
 5 5 7 8 8 17 17    left max
 
 rerun code swap(x, y)
 
 */