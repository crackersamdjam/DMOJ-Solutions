#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    double a = 0;
    for(int j = 0; j < n; j++){
        int m;
        scanf("%d", &m);
        char string[m];
        scanf("%s", string);
        for(int i = 1; i <= m/2 +1; i++){
            if(m%i == 0){
                bool yes = true;
                for(int j = 0; j < m; j++){
                    if(string[j] != string[j%i]){
                        yes = false;
                        break;
                    }
                }
                if(yes) a = fmax(a, (double)(1.0*i) / ((double)(1.0*m)/(double)(1.0*i)));
            }
        }
    }
    printf("%g\n", a);
    return 0;
}