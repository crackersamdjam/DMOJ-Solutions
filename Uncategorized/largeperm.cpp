#include <bits/stdc++.h>
using namespace std;

void init(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
    #endif
}
const int MM = 1e5+2;
int n, k, a[MM];
set<pair<int, int>, greater<pair<int, int>>> st;

int main(){
    init();
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
        st.insert({a[i], i});
    }
    int t=0;
    while(k-- and st.size() and t < n){
        auto rm = *st.begin();
        int id = rm.second;
        if(a[id] == a[t])
            t++;
        st.erase(rm);
        if(id < t)
            k++;
        else{
            if(st.count({a[t], t}))
                st.erase({a[t], t});
            swap(a[id], a[t]);
            st.insert({a[id], id});
            t++;
        }
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<' ';
    
    return 0;
}