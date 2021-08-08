#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, pair<int, int>> pii;
const int MM = 1e5+5;

int n, k;
vector<vector<int>> v;
priority_queue<pii> q;
ll add;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>k;
    for(int i = 1,m; i <= n; i++){
        cin>>m;
        vector<int> in;
        while(m--){
            int a; cin>>a;
            in.emplace_back(a);
        }
        sort(all(in), greater<int>());
        int s = in[0];
        add += in[0];
        for(int &j: in)
            j -= s;
    
        if(in.size() > 1)
            v.emplace_back(in);
    }
    sort(all(v));
    
    v.emplace_back();
    v.back().emplace_back(0);
    
    reverse(all(v));
    
    q.push({0, {0, 0}});
    while(k--){
        ll curd = q.top().first;
        int i = q.top().second.first, j = q.top().second.second;
        q.pop();
        
        cout<<curd+add<<' ';
        
        if(j+1 < v[i].size()){
            q.push({curd+v[i][j+1]-v[i][j], {i, j+1}});
        }
        if(i+1 < v.size()){
    
            //ignore this list and go to next
            if(j == 1)
                q.push({curd+v[i+1][1]-v[i][1], {i+1, 1}});
            
            //still has stuff from this, but now in next
            q.push({curd+v[i+1][1], {i+1, 1}});
        }
    }
}