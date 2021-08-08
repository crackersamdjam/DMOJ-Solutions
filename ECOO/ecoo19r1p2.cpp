#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

using namespace std;
typedef long long ll;

int tc = 10, R, T;
string str, b[30];
ll last[200], cur[200];
char st, ed, a[30];
bool has[200];

int main(){
    
    while(tc--){
        
        memset(last, 0, sizeof last);
        memset(cur, 0, sizeof cur);
        memset(has, 0, sizeof has);
        
        cin >> R >> T >> str;
        
        for(int i = 0; i < R; i++){
            cin >> a[i] >> b[i];
            has[a[i]] = 1;
        }
        
        for(int i = 0; i < str.size(); i++)
            last[str[i]]++;
        
        st = str[0], ed = str.back();
        
        
        while(T--){
            
            for(int i = 0; i < R; i++){
                
                for(int j = 0; j < b[i].size(); j++)
                    cur[b[i][j]] += last[a[i]];
            }
            
            for(int i = 0; i < R; i++){
                if(st == a[i]){
                    st = b[i][0];
                    break;
                }
            }
            
            for(int i = 0; i < R; i++){
                if(ed == a[i]){
                    ed = b[i].back();
                    break;
                }
            }
            
            for(int j = 0; j < 200; j++){
                if(!has[j])
                    cur[j] += last[j];
                //was not replaced
            }
    
            for(int j = 0; j < 200; j++){
                last[j] = cur[j];
                cur[j] = 0;
            }
        }
        
        ll ans = 0;
        for(int i = 0; i < 200; i++)
            ans += last[i];
        
        cout << st << ed << " " << ans << '\n';
    }
    
    return 0;
}