#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}

using namespace std;

string a[20001];
int N, ans;
unordered_map<string, unordered_set<int>> mp;
unordered_map<string, int> cnt;

int main(){
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    for(int i = 0; i < N; i++)
        cin >> a[i];
    
    sort(a, a+N, [](string x, string y){
        return x.size() > y.size();
    });
    
    for(int i = 0; i < N; i++){
        cnt[a[i]]++;
        ans += mp[a[i]].size();
        for(int j = 0; j < a[i].size(); j++){
            for(int k = 1; j+k <= a[i].size(); k++){
                mp[a[i].substr(j, k)].insert(i);
            }
        }
    }
    
    for(auto i: cnt)
        ans += (i.second)*(i.second-1)/2;
    
    print(ans);
    
    return 0;
}