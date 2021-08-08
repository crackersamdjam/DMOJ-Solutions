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

int n, k, a[11], cnt;
int v[MM][11];
bool done[MM];
queue<int> q;
vector<pair<int, int>> st[11];
int ptr[11];

bool good(int i){
    if(done[i])
        return 0;
    for(int j = 0; j < k; j++){
        if(v[i][j] > a[j])
            return 0;
    }
    return 1;
}

void add(int i){
    for(int j = 0; j < k; j++)
        a[j] += v[i][j];
    cnt++;
    //printf("add %d\n", i);
}

int main(){
    
    scan(n, k);
    
    for(int i = 0; i < k; i++)
        scan(a[i]);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            scan(v[i][j]);
            st[j].push_back({v[i][j], i});
        }
        if(good(i)){
            q.push(i);
            //add(i);
            done[i] = 1;
        }
    }
    
    for(int i = 0; i < k; i++){
        sort(st[i].begin(), st[i].end());
    }
    
    while(!q.empty()){
        int rm = q.front(); q.pop();
        add(rm);
        for(int j = 0; j < k; j++){
            int &it = ptr[j];
            while(it < n && st[j][it].first <= a[j]){
                
                int nx = st[j][it].second;
                
                if(good(nx)){
                    done[nx] = 1;
                    q.push(nx);
                }
                it++;
            }
        }
    }
    
    print(cnt);
    
    return 0;
}