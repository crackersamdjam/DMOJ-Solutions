#include <iostream>
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d", n >=m ? m-1 : n);
    return 0;
}