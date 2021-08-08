#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MM = 5e5+5;

int m, n, last[6];
pair<pii, int> a[MM];
ll ans;
vector<pii> v, on[6];
vector<pair<pii, int>> out;

int main(){
    
    scan(m, n);
    
    for(int i = 0; i < n; i++){
        scan(a[i].first.first, a[i].first.second);
        a[i].second = i+1;
    }
    
    sort(a, a+n, greater<pair<pii, int>>());
    
    int rem = m*6;
    for(int i = 0; i < n; i++){
        ll sub = min(rem, a[i].first.second);
        v.emplace_back(sub, a[i].second);
        ans += sub*a[i].first.first;
        rem -= sub;
        if(!rem) break;
    }
    
    print(ans);
    
    sort(v.begin(), v.end(), greater<pii>());
    
    for(int j = 0; j < 6; j++)
        on[j].emplace_back(0, 0);
    
    for(int i = 0; i < v.size(); i++){
        //print(v[i].first, v[i].second);
        for(int j = 0; j < 6; j++){
            int sub = min(v[i].first, m - last[j]);
            if(sub){
                v[i].first -= sub;
                on[j].emplace_back(sub, v[i].second);
                last[j] += sub;
            }
        }
    }
    //make sure every spot is filled
    /*
    for(int j = 0; j < 6; j++){
        if(on[j].size() == 1){
            for(int k = 0; k < 6; k++){
                if(on[k].size() > 2){
                    pii rm = on[k].back();
                    on[k].pop_back();
                    for(int l = 0; l < 6; l++){
                        if(on[l].size() > 1 and on[l][1].second == rm.second){
                            rm.first += on[l][1].first;
                            on[l].erase(on[l].begin()+1);
                        }
                    }
                    on[j].emplace_back(rm);
                    break;
                }
            }
        }
    }
    */
    for(int j = 0; j < 6; j++){
        printf("%d ", on[j][1].second);
        for(int i = 2; i < on[j].size(); i++){
            on[j][i].first += on[j][i-1].first;
            out.emplace_back(on[j][i-1], on[j][i].second);
        }
    }
    pc(10);
    print(out.size());
    sort(out.begin(), out.end());
    for(auto i: out)
        print(i.first.first, i.first.second, i.second);
    
    return 0;
}