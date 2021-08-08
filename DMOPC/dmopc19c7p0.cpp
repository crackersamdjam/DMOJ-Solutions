#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v[5];
double a[4];

int main(){
    cin>>a[0]>>a[1]>>a[2]>>a[3];
    for(int i = 1; i <= (1<<4); i++){
        vector<int> vv;
        for(int j = 0; j < 4; j++){
            if(i&(1<<j))
                vv.push_back(j);
        }
        if(vv.size() > 1)
            v[vv.size()].push_back(vv);
    }
    cout<<fixed<<setprecision(6);
    for(auto i: v){
        sort(i.begin(), i.end());
        for(auto j: i){
            double s = 0;
            for(auto k: j)
                s += a[k];
            cout<<s/j.size()<<'\n';
        }
    }
    
    return 0;
}