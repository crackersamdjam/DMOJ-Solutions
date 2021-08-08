#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1e9+7;

vector<string> str;
string s, st;
int N;
stack<ll> mul;
map<string, ll> ans;

int main(){
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    getline(cin, s);
    getline(cin, s);
    
    stringstream ss(s);
    
    while(ss){
        ss >> st;
        str.push_back(st);
    }
    
    mul.push(1);
    
    for(int i = str.size()-2; i >= 0; i--){
        if(str[i][0] >= '0' and str[i][0] <= '9' and str[i-1] == ")"){
            mul.push(mul.top() * stoi(str[i]) % mod);
            i--;
        }
        else if(str[i] == "(")
            mul.pop();
        else{
            ans[str[i-1]] += stoi(str[i]) * mul.top() % mod;
            ans[str[i-1]] %= mod;
            i--;
        }
    }
    
    for(auto &i: ans)
        cout << i.first << ' ' << i.second << '\n';
    
    return 0;
}