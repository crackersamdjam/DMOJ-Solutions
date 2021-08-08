#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

using namespace std;

int tc = 10, cnt;

unordered_map<string, bool> vis;

inline int count(string str, char c){
    int ret = 0;
    for(int i = 0; i < 8; i++)
        if(str[i] == c)
            ret++;
    return ret;
}

void go(string str){
    for(int i = 0; i <= 8; i++){
        if(i == 8){
            //check count
            if(count(str, 'K') != 1 || count(str, 'Q') != 1 || count(str, 'R') != 2
               || count(str, 'B') != 2 || count(str, 'N') != 2)
                return;
            
            int k = -1, r1 = -1, r2 = -1;
            //check rooks
            for(int i = 0; i < 8; i++){
                if(str[i] == 'K')
                    k = i;
                if(str[i] == 'R'){
                    if(r1 == -1)
                        r1 = i;
                    else
                        r2 = i;
                }
            }
            
            //check bihops opposite colour
            int b1 = -1, b2 = -1;
            for(int i = 0; i < 8; i++){
                if(str[i] == 'B'){
                    if(b1 == -1)
                        b1 = i;
                    else
                        b2 = i;
                }
            }
            
            if(b1%2 == b2%2)
                return;
            
            if(r1 < k and k < r2 and !vis[str]){
                cnt++;
                vis[str] = 1;
            }
            
            return;
        }
        if(str[i] == '_'){
            str[i] = 'K';
            go(str);
            str[i] = 'Q';
            go(str);
            str[i] = 'R';
            go(str);
            str[i] = 'B';
            go(str);
            str[i] = 'N';
            go(str);
            return;
        }
    }
}

int main(){
    
    while(tc--){
        
        vis.clear();
        
        cnt = 0;
        string str;
        cin >> str;
        
        go(str);
        
        print(cnt);
    }
    
    return 0;
}