#include <bits/stdc++.h>
using namespace std;
const int MM = 2002;

int n, a[MM][MM], r[MM], c[MM], cnt;

int main(){
    cin>>n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>a[i][j];
        }
    }
    for(int j = 0; j < n; j++){
        if(a[0][j]){
            c[j] = 1;
            cnt++;
        }
    }
    for(int i = 1; i < n; i++){
        if(a[i][0]^c[0]){
            r[i] = 1;
            cnt++;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j]^r[i]^c[j])
                return puts("-1"), 0;
        }
    }
    cout<<cnt<<'\n';
    for(int i = 0; i < n; i++){
        if(r[i])
            cout<<"R "<<i+1<<'\n';
        if(c[i])
            cout<<"C "<<i+1<<'\n';
    }
    return 0;
}