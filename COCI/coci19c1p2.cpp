#include <bits/stdc++.h>
using namespace std;

void init(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
    #endif
}

using ll = long long;
ll a, b;

bool prime(ll x){
    x = abs(x);
    if(x < 2) return 0;
    for(ll i = 2; i*i <= x; i++)
        if(x % i == 0)
            return 0;
    return 1;
}

void run(ll c){
    if(prime(c) and prime(a-c) and prime(c-b)){
        cout<<"3\n"<<a<<' '<<c<<' '<<b;
        exit(0);
    }
}

map<ll, map<ll, bool>> dif;
map<ll, bool> vis;
vector<ll> st;

void go(ll u){
    st.emplace_back(u);
    if(u == b){
        cout<<st.size()<<'\n';
        for(ll i: st)
            cout<<i<<' ';
        exit(0);
    }
    vis[u] = 1;
    for(auto nx: dif[u])
        if(nx.second and !vis[nx.first])
            go(nx.first);
    st.pop_back();
}

int main(){
    init();
    cin>>a>>b;
    vector<ll> v,z = {a,b,2,a+2,a-2,b+2,b-2};
    for(ll i: z)
        if(prime(i))
            v.emplace_back(i);
    for(ll i: v)
        for(ll j: v)
            dif[i][j] = prime(i-j);
    go(a);

    puts("-1");
    
    return 0;
}