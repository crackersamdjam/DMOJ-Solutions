#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}

using namespace std;
const int MM = 1e5;

int N, st[MM];
vector<int> nx[26][MM];
string str, ans;

int find(int i, char c){
    c -= 'a';
    while(!nx[c][i].empty() and nx[c][i].back() < st[i])
        nx[c][i].pop_back();
    
    return nx[c][i].empty() ? -1: nx[c][i].back();
}

int main(){
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> str;
        for(int j = str.size()-1; j >= 0; j--)
            nx[str[j]-'a'][i].push_back(j);
    }
    
    for(char c = 'z'; c >= 'a'; c--){
        
        while(1){
            
            for(int i = 0; i < N; i++){
                if(find(i, c) == -1)
                    goto out;
            }
            
            for(int i = 0; i < N; i++){
                int at = find(i, c);
                st[i] = at+1;
            }
            
            ans += c;
        }
        out:;
    }
    
    if(ans.empty())
        puts("-1");
    else
        cout << ans << '\n';
    
    return 0;
}