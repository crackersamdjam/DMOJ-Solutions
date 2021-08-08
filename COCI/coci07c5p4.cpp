#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1e5+1;

int n, a[3][MM], cnt[3][MM], ans;
bool del[MM];
map<int, int> mp;
queue<int> q;

int main(){
    
    scan(n);
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < n; j++){
            scan(a[i][j]);
            cnt[i][a[i][j]]++;
            if(i == 0){
                mp[a[i][j]] = j;
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        int c = a[0][i];
        if(cnt[1][c] == 0 || cnt[2][c] == 0){
            cnt[0][c]--, cnt[1][a[1][i]]--, cnt[2][a[2][i]]--;
            //print(i+1);
            ans++;
            del[i] = 1;
            q.push(mp[a[1][i]]);
            q.push(mp[a[2][i]]);
        }
    }
    
    while(!q.empty()){
        int i = q.front(); q.pop();
        if(del[i])
            continue;
        int c = a[0][i];
        if(cnt[1][c] == 0 || cnt[2][c] == 0){
            cnt[0][c]--, cnt[1][a[1][i]]--, cnt[2][a[2][i]]--;
            //print(i+1);
            ans++;
            del[i] = 1;
            q.push(mp[a[1][i]]);
            q.push(mp[a[2][i]]);
        }
    }
    
    print(ans);
    
    return 0;
}