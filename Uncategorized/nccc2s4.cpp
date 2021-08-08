#include <bits/stdc++.h>
#define f first
#define s second
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
typedef pair<int, int> pii;
const int MM = 5e4+1;

int N, root = -1, root2 = -1;
bool no[MM];
vector<pii> adj[MM];
vector<int> ans, rc, rc2;
map<int, vector<int>> nodes[MM];

void dfs(int cur, int pre, bool v){
    v |= no[cur];
    no[cur] = v;
    for(auto e: adj[cur]){
        if(e.f == pre)
            continue;
        dfs(e.f, cur, v);
    }
}

int main(){
    
    scan(N);
    
    for(int i = 0,a,b,c; i < N-1; i++){
        scan(a, b, c);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    for(int i = 1; i <= N; i++){
        for(auto e: adj[i]){
            nodes[i][e.s].push_back(e.f);
        }
        for(auto vec: nodes[i]){
            if(vec.second.size() > 1){
                if(root == -1){
                    root = i;
                    for(int u: vec.second){
                        no[u] = 1;
                        rc.push_back(u);
                    }
                }else if(root2 == -1){
                    root2 = i;
                    for(int u: vec.second){
                        no[u] = 1;
                        rc2.push_back(u);
                    }
                }else{
                    for(int u: vec.second){
                        no[u] = 1;
                    }
                }
            }
        }
    }
    
    if(root != -1){
        //dfs(root, -1, 0);
        for(int u: rc){
            dfs(u, root, 0);
        }
    }
    
    if(root2 != -1){
        //dfs(root2, -1, 0);
        for(int u: rc2){
            dfs(u, root2, 0);
        }
    }
    
    for(int i = 1; i <= N; i++){
        if(!no[i]){
            ans.push_back(i);
        }
    }
    
    print(ans.size());
    
    //sort(ans.begin(), ans.end());
    
    for(int i: ans)
        print(i);
    
    return 0;
}
/*
 * if two in row and either has children, ans is 0 for entire graph
 * except those being through center node
 * otherwise, make ends as defunct

5
1 2 1
2 3 1
3 4 2
3 5 2

should be
1
2
 */