#include <bits/stdc++.h>
#define all(x) x.begin, x.end()
using namespace std;
using ll = long long;
using ld = long double;
const int MM = 4005;
const ld eps = 1e-7;

int n, w[MM], x[MM], y[MM], ans, allsum;
struct st{
    ld ang; int x, y, w;
};

vector<st> v;

bool check(int a, int b){
    ld aa = v[a].ang, bb = v[b].ang;
    if(b < a){
        return aa-bb < M_PI;
        //if now > aa
    }
    else{
        bb -= 2*M_PI;
        return aa-bb < M_PI;
    }
}
//positive if a is clockwise from b

bool colin(int a, int b){
    if(b == n-1){
        b = 0;
        return abs(v[a].ang - (v[b].ang+2*M_PI)) < eps;
    }
    return abs(v[a].ang - v[b].ang) < eps;
}

bool opposite(int a, int b){
    if(a > b)
        swap(a, b);
    return abs(v[a].ang+M_PI - v[b].ang) < eps;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>x[i]>>y[i]>>w[i];
        allsum += w[i];
    }
    ans = max(0, allsum);
    //choose all or none
    if(n == 2){
        ans = max({ans, w[0], w[1]});
        cout<<ans<<'\n';
        return 0;
    }
    
    for(int i = 0; i < n; i++){
        //choose i as root to rotate around
        v.clear();
        
        for(int j = 0; j < n; j++){
            if(j == i)
                continue;
            
            ld ang = atan2l(y[j]-y[i], x[j]-x[i]);
            while(ang < 0)
                ang += 2*M_PI;
            v.push_back({ang, x[j]-x[i], y[j]-y[i], w[j]});
        }
        sort(v.begin(), v.end(), [](st f, st s){
            return f.ang < s.ang;
        });
        
        int sum = allsum;
        
        int l = 0, r = 0;
        
        for(r = 0; r < v.size(); r++){
            sum += v[r].w;
            
            if(l == r){
                //move up once
                sum -= v[l].w;
                l++;
                if(l == v.size())
                    l = 0;
            }
            while(check(l, r)){
                sum -= v[l].w;
                l++;
                if(l == v.size())
                    l = 0;
            }
            
            if(!colin(r, r+1)){
                ans = max(ans, sum);
                if(!opposite(l, r)){
                    ans = max(ans, sum-w[i]);
                }
            }
        }
    }
    
    cout<<ans<<'\n';
}