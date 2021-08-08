#include <bits/stdc++.h>
#define MM 257
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
int tc = 5, i;
string a, b;
int main(){
    while(tc--){
        getline(cin,a);
        getline(cin,b);
        for(i = 0; i < min(a.length(), b.length()); i++){
            if(a[i] == '\n' || b[i] == '\n'|| a[i] != b[i])
                break;
        }
        printf("%d\n", i);
    }
    return 0;
}