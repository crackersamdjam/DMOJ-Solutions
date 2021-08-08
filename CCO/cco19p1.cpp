#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;

int R, C, E[2];

map<string, double> dp[2];

double go(int t, string s){
    if(dp[t].count(s))
        return dp[t][s];
    
    vector<double> v;
    
    char c = (t?'D':'J');
    
    for(int i = 0; i < R*C; i++){
        if(s[i] == c){
            
            int nx;
            string ns;
            
            nx = i+1;
            if(nx < R*C && nx/C == i/C && s[nx] != '_'){
                ns = s;
                ns[i] = '_';
                ns[nx] = c;
                v.push_back(go(t^1, ns));
            }
            
            nx = i-1;
            if(nx >= 0 && nx/C == i/C && s[nx] != '_'){
                ns = s;
                ns[i] = '_';
                ns[nx] = c;
                v.push_back(go(t^1, ns));
            }
            
            nx = i+C;
            if(nx < R*C && s[nx] != '_'){
                ns = s;
                ns[i] = '_';
                ns[nx] = c;
                v.push_back(go(t^1, ns));
            }
            
            nx = i-C;
            if(nx >= 0 && s[nx] != '_'){
                ns = s;
                ns[i] = '_';
                ns[nx] = c;
                v.push_back(go(t^1, ns));
            }
        }
    }
    
    if(v.empty())
        return dp[t][s] = 0;
    
    sort(v.begin(), v.end());
    
    double avg = 0;
    for(int i = 0; i < min((int)v.size(), E[t]); i++)
        avg += 1-v[i];
    
    avg /= min((int)v.size(), E[t]);
    
    return dp[t][s] = avg;
}

int main(){
    
    cin >> R >> C;
    
    string s = "";
    
    for(int i = 0; i < R; i++){
        string ss;
        cin >> ss;
        s += ss;
    }
    
    cin >> E[0] >> E[1];
    
    printf("%.3lf\n", go(0, s));
    
    return 0;
}