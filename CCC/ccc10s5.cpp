#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
const int MM = 420;

int dp[2501][MM], lc[MM], rc[MM], a[MM], n, ind, X, leftv[2501], rightv[2501];
string str;

inline int read(){
    int ret = 0;
    while(str[ind] >= '0' && str[ind] <= '9'){
        ret = ret*10 + str[ind] - '0';
        ind++;
        if(ind >= str.length())
            break;
    }
    return ret;
}

void input(int id){
    if(ind >= str.length())
        return;
    
    while(str[ind] == ' ')
        ind++;
    
    if(str[ind] == '('){
        ind++;
        lc[id] = ++n;
        input(n);
    }
    else if(str[ind] == ')'){
        ind++;
        return;
    }else{
        //number
        lc[id] = ++n;
        a[n] = read();
    }
    
    if(ind >= str.length())
        return;
    
    while(str[ind] == ' ')
        ind++;
    
    if(str[ind] == '('){
        ind++;
        rc[id] = ++n;
        input(n);
    }
    else if(str[ind] == ')'){
        ind++;
        return;
    }else{
        //number
        rc[id] = ++n;
        a[n] = read();
    }
    //if finished reading two numbers )
    
    while(str[ind] == ' ')
        ind++;
    if(str[ind] == ')')
        ind++;
}

void go(int m){
    
    if(a[m]){
        for(int i = 0; i <= X; i++)
            dp[i][m] = a[m] + i;
        
        return;
    }
    
    go(lc[m]);
    if(rc[m])
        go(rc[m]);
    
    for(int i = 0; i <= X; i++){
        
        leftv[i] = rightv[i] = 0;
        
        for(int j = 0; j <= i; j++)
            leftv[i] = max(leftv[i], min((j+1)*(j+1), dp[i-j][lc[m]]));
        
        for(int j = 0; j <= i; j++)
            rightv[i] = max(rightv[i], min((j+1)*(j+1), dp[i-j][rc[m]]));
    }
    
    for(int i = 0; i <= X; i++)
        for(int j = 0; j <= i; j++)
            dp[i][m] = max(dp[i][m], leftv[j] + rightv[i-j]);
}

int main(){
    
    getline(cin, str);
    
    input(n);
    
    scan(X);
    
    go(1);
    
    print(dp[X][1]);
    
    return 0;
}