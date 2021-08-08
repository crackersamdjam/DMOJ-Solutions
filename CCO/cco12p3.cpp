#include <bits/stdc++.h>

using namespace std;

string str;
int v, t, r1, r2, w;
int dp[26][30][30];

map<char, int> vow;

struct p{
    int a, b, c;
}
one[30], two[30];

bool go(int va, int l, int r){
    
    int &ret = dp[va][l][r];
    
    if(~ret)
        return ret;
    
    if(l == r){
        for(int i = 0; i < r1; i++){
            if(one[i].a == va && one[i].b == str[l])
                return ret = 1;
        }
        return ret = 0;
    }
    
    for(int i = l; i < r; i++){
        for(int j = 0; j < r2; j++){
            if(two[j].a == va && go(two[j].b, l, i) && go(two[j].c, i+1, r))
                return ret = 1;
        }
    }
    return ret = 0;
}

int main(){
    
    cin >> v >> t;
    
    for(int i = 0; i < v; i++){
        char a;
        cin >> a;
        vow[a] = i;
    }
    
    for(int i = 0; i < t; i++){
        char a;
        cin >> a;
    }
    
    cin >> r1;
    
    for(int i = 0; i < r1; i++){
        char a, b;
        cin >> a >> b;
        one[i] = {vow[a], b};
    }
    
    cin >> r2;
    
    for(int i = 0; i < r2; i++){
        char a, b, c;
        cin >> a >> b >> c;
        two[i] = {vow[a], vow[b], vow[c]};
    }
    
    cin >> w;
    
    while(w--){
        memset(dp, -1, sizeof dp);
        cin >> str;
        cout << go(0, 0, str.size()-1) << '\n';
    }
    
    return 0;
}