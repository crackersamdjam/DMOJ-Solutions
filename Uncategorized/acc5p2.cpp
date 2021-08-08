#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
int ans = 4;
char l[] = {'D', 'M', 'O', 'J'};

void go(string s, int d){
    if(s.find("DMOJ") != string::npos)
        ans = min(ans, d);
    if(s.size() == 8)
        return;
    for(int c = 0; c < 4; c++){
        for(int i = 0; i <= s.size(); i++){
            string n = s.substr(0, i) + l[c] + s.substr(i);
            if(d+1 < ans)
                go(n, d+1);
        }
    }
}

int main(){
    
    string s;
    cin >> s;
    
    go(s, 0);
    
    print(ans);
    
    return 0;
}