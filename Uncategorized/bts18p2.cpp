#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+2;
int psa[26][MM],Q;
string str;
int main(){
    getline(cin, str);
    for(int i = 0; i < str.size(); i++){
        for(int j = 0; j < 26 && i > 0; j++)
            psa[j][i+1] = psa[j][i];
        if(str[i] != ' ')
            psa[str[i]-'a'][i+1]++;
    }
    scanf("%d",&Q);
    char c;
    for(int i = 0,a,b; i < Q; i++){
        scanf("%d %d %c",&a,&b,&c);
        int ans = psa[c-'a'][b];
        if(a != 0)
            ans -= psa[c-'a'][a-1];
        printf("%d\n", ans);
    }
    return 0;
}