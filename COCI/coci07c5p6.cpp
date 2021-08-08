#include <bits/stdc++.h>
template<typename T> void printn(T n){std::cout<<n;}
template<typename T> void print(T n){std::cout<<n<<std::endl;}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);std::cout<<' ';print(rest...);}

using namespace std;
constexpr int MM = 3e4+1, MN = 210000;

int n, q, out[MM];
string a[MM], qs[MM];


int ptr, l, r;
pair<int, int> add[MM];
pair<string, int> mp[MM];

using T = string;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> bbst;
bbst t;

int main(){
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
//        a[i].push_back('z'+1);
        mp[i] = {a[i], i};
    }
    sort(mp+1, mp+1+n);
    cin>>q;
    for(int i = 0; i < q; i++){
        cin>>qs[i];
//        qs[i].push_back('z'+1);
        int id = lower_bound(mp+1, mp+1+n, make_pair(qs[i], 0)) - mp;
        if(mp[id].first == qs[i]){
            add[r++] = {mp[id].second, i};
        }
        else{
            add[r++] = {n+1, i};
        }
    }
    sort(add, add+r);
    for(int i = 1; i <= n; i++){
        //insert
        t.insert(a[i]);
        
        //answer query
        while(l < r and add[l].first == i){
            int id = add[l++].second;
            out[id] = i;
//            print("at", qs[id], i);
            for(int j = 0; j < qs[id].size(); j++){
                string s = qs[id].substr(0, j+1);
                s.back()++;
                int cnt = t.order_of_key(s);
//                print("f", s, cnt);
                s.back()--;
//                print("s", s);
                cnt -= t.order_of_key(s);
                out[id] += cnt;
//                print("add", j, cnt);
            }
        }
    }
    while(l < r){
        int id = add[l++].second;
        out[id] = n;
//        print("at", qs[id], n);
        for(int j = 0; j < qs[id].size(); j++){
            string s = qs[id].substr(0, j+1);
            s.back()++;
            int cnt = t.order_of_key(s);
//            print("f", s, cnt);
            s.back()--;
//            print("s", s);
            cnt -= t.order_of_key(s);
            out[id] += cnt;
//            print("add", j, cnt);
        }
    }
    
    for(int i = 0; i < q; i++){
        print(out[i]);
    }
    
    return 0;
}