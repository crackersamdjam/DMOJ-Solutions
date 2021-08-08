#include <bits/stdc++.h>
using namespace std;


int n, a[1001], b[1001],cnt;

int main(){
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>a[i];
    bool on = 0;
    for(int i = 0; i < n; i++){
        cin>>b[i];
        if(b[i]==a[i]){
            if(!on){
                on = 1;
                cnt++;
            }
        }
        else
            on = 0;
    }
    cout<<cnt;
    return 0;
}