#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using pii = pair<int, int>;
const int MM = 2e5+5;

int n, m, dp[MM];
pair<int, int> a[MM];

int main(){
    scan(n, m);
    for(int i = 0; i < m; i++)
        scan(a[i].first, a[i].second);
    sort(a, a+m);
    memset(dp, -0x3f, sizeof dp);
    dp[0] = 0;
    int maxlout = 0;
    multiset<pii> in;
    multiset<int> minlin;
    deque<pii> q;
    //q.emplace_back(0, 0);
    
    for(int i = 1, l = 0, j = 0; i <= n+1; i++){
        //add segment to in
        while(l < m and a[l].first <= i){
            in.insert({a[l].second, a[l].first});
            minlin.insert(a[l].first);
            l++;
        }
        //mv segment from in to out
        while(in.size() and in.begin()->first < i){
            minlin.erase(minlin.lower_bound(in.begin()->second));
            maxlout = max(maxlout, in.begin()->second);
            in.erase(in.begin());
        }
        //insert dp[j] into q
        while((minlin.empty() and j < i) or j < *minlin.begin()){
            while(q.size() and q.back().first <= dp[j])
                q.pop_back();
            q.emplace_back(dp[j], j);
            j++;
        }
        //pop q front
        while(q.size() and q.front().second < maxlout)
            q.pop_front();
        //set current dp
        if(q.size()){
//            print(i, q.front().first, q.front().second);
            dp[i] = q.front().first + 1;
        }
    }
    
    int ans = dp[n+1]-1;
    if(ans < 0)
        ans = -1;
    
    print(ans);
    
    return 0;
}