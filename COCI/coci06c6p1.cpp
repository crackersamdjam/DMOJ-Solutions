#include <bits/stdc++.h>
using namespace std;
int arr[102],N,n,ind=1,cnt=0;
unordered_map<string,int> mp;
string str;
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> str;
        if(mp[str]){
            n = mp[str];
        }else{
            mp[str] = n = ind++;
        }
        if(arr[n] > (i-1)/2)
            cnt++;
        arr[n]++;
    }
    printf("%d\n",cnt);
    return 0;
}