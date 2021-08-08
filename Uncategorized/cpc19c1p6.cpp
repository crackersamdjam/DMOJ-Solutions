#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}

using namespace std;
const int sz = 1200;

int N, Q, pre, last;
vector<vector<int>> block(101);
vector<unordered_map<int, int>> cnt(101);

inline int find(int &ind){
    int num = 0;
    while(ind >= block[num].size())
        ind -= block[num++].size();
    return num;
}

int main(){
    
    scan(N, Q);
    
    int bn = 0, bi = 0;
    for(int i = 1,a; i <= N; i++){
        scan(a);
        block[bn].emplace_back(a);
        cnt[bn][a]++;
        if(++bi == sz)
            bn++, bi = 0;
    }
    
    block[bn].emplace_back(-1);
    cnt[bn][-1]++;
    
    last = bn;
    
    for(int t = 0,op,ind,x,l,r; t < Q; t++){
        op = gc;
        if(op == 'I'){
            scan(ind, x);
            ind ^= pre, x ^= pre;
            int at = find(ind);
    
            block[at].insert(block[at].begin() + ind, x);
            cnt[at][x]++;
            
            if(block[at].size() > 2*sz){
                if(at == last){
                    block.emplace_back(vector<int>());
                    cnt.emplace_back(unordered_map<int, int>());
                }
                else{
                    block.insert(block.begin()+at+1, vector<int>());
                    cnt.insert(cnt.begin()+at+1, unordered_map<int, int>());
                }
                last++;
                for(int i = sz; i < block[at].size(); i++){
                    int v = block[at][i];
                    cnt[at+1][v]++;
                    cnt[at][v]--;
                }
                block[at+1].insert(block[at+1].begin(), block[at].begin() + sz, block[at].end());
                block[at].resize(sz);
            }
        }
        else if(op == 'D'){
            scan(ind);
            ind ^= pre;
            ind--;
            int at = find(ind);
            cnt[at][block[at][ind]]--;
            block[at].erase(block[at].begin() + ind);
        }
        else{
            scan(l, r, x);
            l ^= pre, r ^= pre, x ^= pre;
            l--, r--;
            int st = find(l), ed = find(r), ans = 0;
            
            if(st != ed){
                for(int i = l; i < block[st].size(); i++)
                    ans += block[st][i] == x;
                
                for(int i = 0; i <= r; i++)
                    ans += block[ed][i] == x;
                
                for(int i = st+1; i < ed; i++)
                    if(cnt[i].find(x) != cnt[i].end())
                        ans += cnt[i][x];
            }
            else{
                for(int i = l; i <= r; i++)
                    ans += block[st][i] == x;
            }
            print(pre = ans);
        }
    }
    
    
    return 0;
}