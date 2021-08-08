#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
const int MM = 30002;

int N, M;
string str, a[MM];
unordered_map<string, int> mp;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        cin >> a[i];
        mp[a[i]] = i;
    }
    sort(a+1, a+N+1);
    
    for(int i = 0,n; i < M; i++){
        cin >> n >> str;
        int st = lower_bound(a+1, a+N+1, str) -a-1;
        if(st+n <= N && a[st+n].substr(0, str.length()) == str){
            cout << mp[a[st+n]] << '\n';
        }
        else
            cout << "-1\n";
    }
    return 0;
}