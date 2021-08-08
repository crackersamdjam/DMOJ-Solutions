#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1e6+1;

int n, rt, st, par[MM], dp[MM], dep[MM];
vector<int> adj[MM];
bool block[MM], done[MM];

struct stt{
    int first, second, third;
};

int dfs1(int cur, int pre){
    par[cur] = pre;
    if(cur != rt)
        dep[cur] = dep[pre] + adj[cur].size()-2;
    
    int f = -1, s = -1;
    for(int u: adj[cur]){
        if(u == pre)
            continue;
        int v = dfs1(u, cur);
        if(v > f)
            s = f, f = v;
        else if(v > s)
            s = v;
        if(u == st){
            dep[cur]--;
            //parent of current does not need to block it when coming back up
            //this cancels out st's -1 jump up
        }
    }
    
    if(f == -1)
        return dp[cur] = 1; // clean & return
    if(s == -1)
        return dp[cur] = 2; //block, clean, return
    return dp[cur] = s + 1 + (adj[cur].size()-2);
    //clean once, block other children
}

vector<stt> vec, rm;

bool test(int k){
    
    memset(done, 0, sizeof done);
    rm.clear();
    
    int w = 0, tp = 0;
    
    for(int i = 0; i < vec.size(); i++){
        auto u = vec[i];
        
        if(i && vec[i].second != vec[i-1].second)
            w += tp, tp = 0;
        
        if(u.second == 0){
            if(u.first > k){
                done[u.third] = 1;
                if(w)
                    return 0;
                w++;
                rm.push_back(u);
            }
            continue;
        }
        
        if(u.first + w > k){
            done[u.third] = 1;
            if(w > u.second)
                return 0; //can not block in time
            
            rm.push_back(u);
            tp++;
        }
    }
    w += tp;
    
    //what is this scam
    
    int cur = st, l = 0;
    while(cur != rt){
        if(l < rm.size()){
            auto u = rm[l++];
            done[u.third] = 0;
        }
        for(int u: adj[cur]){
            if(block[u] || u == par[cur] || !done[u])
                continue;
            return 0;
        }
        cur = par[cur];
    }
    
    return w <= k;
}

int main(){
    
    scan(n, rt, st);
    
    for(int i = 0,a,b; i < n-1; i++){
        scan(a, b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs1(rt, -1);
    
    for(int i = 1; i <= n; i++)
        dp[i] += dep[par[i]];
    
    int x = st, d = 0;
    
    while(x != rt){
        for(int u: adj[x]){
            if(u != par[x] && !block[u])
                vec.push_back({dp[u] - (d >= 2), d, u});
        }
        block[x] = 1;
        x = par[x];
        d++;
    }
    
    sort(vec.begin(), vec.end(), [](stt x, stt y){
        if(x.second != y.second)
            return x.second < y.second;
        return x.first > y.first;
    });
    
    int low = 0, mid, high = 1e8, ans = 1e8;
    
    while(low <= high){
        mid = (low + high)/2;
        if(test(mid)){
            ans = min(ans, mid);
            high = mid-1;
        }else
            low = mid+1;
    }
    
    print(ans);
    
    return 0;
}