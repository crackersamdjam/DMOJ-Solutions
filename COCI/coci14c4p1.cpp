#include <bits/stdc++.h>
using namespace std;
#define MM 100002
char c[MM];
vector<int> v;
int main() {
    memset(c, 'a', sizeof(c));
    scanf("%s", c);
    bool zero = false;
    int sum = 0;
    for(int i = 0; i < MM; i++){
        if(c[i] == 'a') {
            v.erase(v.begin()+i-1);
            break;
        }
        if(c[i]=='0') zero = true;
        v.push_back((int)(c[i]) - '0');
        //printf("%d\n", (int)(c[i]) - '0');
        sum += (int)(c[i]) - '0';
    }
    if((sum%3 == 0) && zero) {
        sort(v.begin(), v.end(), greater<int>());
        for (int i: v) printf("%d", i);
    }else printf("-1");
    return 0;
}