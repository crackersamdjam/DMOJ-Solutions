#define ONLINE_JUDGE

#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

#ifndef ONLINE_JUDGE
template<typename T>
void printerr(T a){std::cout<<a<<std::endl;}
template<typename T,typename... Args>
void printerr(T a, Args... args) {std::cout<<a<<' ',printerr(args...);}
#else
template<typename... Args>
void printerr(Args... args){}
#endif

using namespace std;

struct st{
    int x, y, loc;
    //loc 1 = up, 2 = left
    bool operator<(const st &o) const{
        return x < o.x;
        //don't need this
    }
};

int n, ax, ay, bx, by, ptx, pty, ptx2, pty2;
int dp[16][16][2];

bool valid(int x, int y){
    return x > 0 and x <= n and y > 0 and y <= n;
}

using pii = pair<int, st>;
priority_queue<pii, vector<pii>, greater<pii>> q;

int main(){
    
    scan(n, ax, ay, bx, by, ptx, pty, ptx2, pty2);
    
    if(ax == bx and ay == by)
        return puts("0"), 0;
    
    if(ptx == ax and pty == ay){
        swap(ptx, ptx2);
        swap(pty, pty2);
    }
    
    if(bx < ax)
        ax = n+1-ax, bx = n+1-bx, ptx = n+1-ptx;
    if(by < ay)
        ay = n+1-ay, by = n+1-by, pty = n+1-pty;
    
    int d = 0;
    
    while(ptx < ax)
        ptx++, d++;
    while(pty < ay)
        pty++, d++;
    
    while(ptx-ax > 1)
        ptx--, d++;
    while(pty-ay > 1)
        pty--, d++;
    
    memset(dp, 0x3f, sizeof dp);
    
    if(ptx == ax and pty == ay){
        dp[ax+1][ay][0] = dp[ax][ay+1][1] = d+2;
        //one to move over, one for ball
    }
    else if(ptx == ax+1 and pty == ay+1){
        dp[ptx][pty-1][0] = dp[ptx-1][pty][1] = d+2;
        //q.push({d+2, {ax, ay, 1}});
        //q.push({d+2, {ax, ay, 2}});
    }
    else if(ptx == ax+1){
        dp[ptx][pty][0] = d+1;
        dp[ptx-1][pty+1][1] = d+3;
        
        //q.push({d+1, {ax, ay, 1}});
        //prev is above
    }
    else if(pty == ay+1){
        dp[ptx+1][pty-1][0] = d+3;
        dp[ptx][pty][1] = d+1;
        //q.push({d+1, {ax, ay, 2}});
    }
    else abort();
    
    for(int i = ax; i <= bx; i++){
        for(int j = ay; j <= by; j++){
            if(i == ax and j == ay) continue;
            if(dp[i][j][0] != 0x3f3f3f3f || dp[i][j][1] != 0x3f3f3f3f) continue;
    
            dp[i][j][0] = min(dp[i-1][j][1] + 3, dp[i-1][j][0] + 5);
            dp[i][j][1] = min(dp[i][j-1][0] + 3, dp[i][j-1][1] + 5);
        }
    }
    
    assert(min(dp[bx][by][0], dp[bx][by][1]) != 0x3f3f3f3f);
    print(min(dp[bx][by][0], dp[bx][by][1]));
    
    
    return 0;
}
/*
3
1 1 3 2
1 1 2 2
8

3
1 1 3 1
1 1 2 2
7
 
 */

/*
    int d = 0;
    while(ptx-ax > 1)
        ptx--, d++;
    while(pty-ay > 1)
        pty--, d++;
    
    if(ptx-ax == 1 and pty-ay == 1){
        if(bx-ax > by-ay)
            pty--, d++;
        else
            ptx--, d++;
    }
    else{
        //see if need to switch side
        if(bx-ax == by-ay);
        else if(bx-ax > by-ay){
            if(ptx == ax){
                //move over
                d += 2;
                ptx = ax+1, pty = ay;
            }
        }
        else{
            if(pty == ay){
                //move over
                d += 2;
                pty = ay+1, ptx = ax;
            }
        }
    }
    printerr("f",  d);
    d += bx-ax+by-ay; //move it
    printerr("f", d);
    
    //move up one
    if(ptx == ax+1){
        ax++;
    }
    else{
        ay++;
    }
    
    if(ax == bx || ay == by){
        int rem = max(bx-ax, by-ay);
        d += rem*4;
        print(d);
        return 0;
    }
    
    printerr("st", ax, ay);
    
    int dia = min(bx-ax, by-ay);
    printerr("dia", dia);
    
    d += dia*4; //blocks travel
    
    int rem = max(bx-ax-dia, by-ay-dia);
    printerr("rem", rem);
    if(rem)
        d += 4*(rem-1) + 2;
    
    print(d);
    */
/*
3 1 1 3 3
1 1
0 0
13
 */