#include <bits/stdc++.h>
using namespace std;
int main() {
    for(int i = 0; i < 5; i++) {
        int d, m, y;
        scanf("%d%d%d", &d, &m, &y);
        bool yes = false;
        if (y < 1997) yes = true;
        else if (y == 1997) {
            if (m < 10) yes = true;
            else if (m == 10) {
                if (d <= 27) yes = true;
            }
        }
        printf(yes ? "old enough\n" : "too young\n");
    }
    return 0;
}