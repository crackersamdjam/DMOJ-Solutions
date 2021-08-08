#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;


int main(){
    
    for(int tc = 5; tc--;){
        string str;
        getline(cin, str);
        str.push_back('$');
        string pat = "#", ans = "";
        int last = -1;
        for(int i = 0; i < str.size()-1; i++){
            
            if(~last){
                if(str.substr(i, pat.size()) == pat){
                    ans += ' ' + str.substr(last, i-last);
                    last = -1;
                }
                continue;
            }
            if(str[i] == '/' and str[i+1] == '/'){
                    str.pop_back();
                    ans += ' ' + str.substr(i+2);
                    break;
            }
            if(str[i] == '/' and str[i+1] == '*'){
                pat = "*/";
                last = i+2;
            }
            if(str[i] == '\'' or str[i] == '\"'){
                pat = str[i];
                last = i+1;
            }
        }
        cout << (ans.empty()? "":ans.substr(1)) + '\n';
    }
    
    return 0;
}