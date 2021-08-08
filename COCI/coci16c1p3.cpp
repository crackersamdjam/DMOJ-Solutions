#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;

int n;
vector<int> adj[200];
string s[100];
int a[100], in[200], to[200], t = 'a';

pair<int, string> p[200];

int main(){
    
    cin >> n;
    
    for(int i = 0; i < n; i++)
        cin >> s[i];
    
    for(int i = 0,d; i < n; i++){
        cin >> d;
        a[d-1] = i;
        //reeeeeeeeee
    }
    
    for(int i = 0; i < n; i++)
        p[i] = {a[i], s[i]};
    
    sort(p, p+n);
    
    for(int i = 0; i < n; i++)
        s[i] = p[i].second, a[i] = p[i].first;
    
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(s[i].find(s[j]) == 0)
                return !puts("NE");
    
            if(s[j].find(s[i]) == 0)
                continue;
            
            int k = 0;
            while(s[i][k] == s[j][k])
                k++;
            //cout << s[i][k] << ' ' << s[j][k] << '\n';
            adj[s[i][k]].push_back(s[j][k]);
            in[s[j][k]]++;
        }
    }
    
    queue<int> q;
    for(int i = 'a'; i <= 'z'; i++)
        if(!in[i])
            q.push(i);
    
    while(!q.empty()){
        int u = q.front(); q.pop();
        to[u] = t++;
        for(int v: adj[u]){
            if(!--in[v])
                q.push(v);
        }
    }
    
    for(int i = 'a'; i <= 'z'; i++)
        if(in[i])
            return !puts("NE");
    
    puts("DA");
    for(int i = 'a'; i <= 'z'; i++)
        pc(to[i]);
    pc(10);
    
    return 0;
}