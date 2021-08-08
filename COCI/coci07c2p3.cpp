#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}

using namespace std;

string r[21], c[21];
vector<string> v;

int main(){
    
    int R, C;
    
    scan(R, C);
    
    for(int i = 0; i < R; i++){
        cin >> r[i];
        int a = 0, b = C-1;
        while(r[i][a] == '#')
            a++;
        while(r[i][b] == '#')
            b--;
        if(a <= b)
            v.push_back(r[i].substr(a, b-a+1));
    }
    
    for(int i = 0; i < C; i++){
        for(int j = 0; j < R; j++)
            c[i] += r[j][i];
        
        int a = 0, b = R-1;
        while(c[i][a] == '#')
            a++;
        while(c[i][b] == '#')
            b--;
        if(a <= b)
            v.push_back(c[i].substr(a, b-a+1));
    }
    
    string ans = "zzzzzzzzzz";
    
    int i = 0;
    while(i < v.size()){
        string s = v[i];
        int ind;
        if((ind = s.find('#')) != string::npos){
            if(ind)
                v.push_back(s.substr(0, ind));
            if(ind+1 < s.size())
                v.push_back(s.substr(ind+1));
        }
        i++;
    }
    
    for(string s: v){
        if(!~s.find('#') && s.size() > 1){
            ans = min(ans, s);
        }
    }
    
    cout << ans;
    
    
    return 0;
}