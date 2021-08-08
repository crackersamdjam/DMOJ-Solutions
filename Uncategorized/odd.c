#include <stdio.h>

int n, a, x;

int main() {
    scanf("%d", &n);
    while(n--){
        scanf("%d", &a);
        x ^= a;
    }
    printf("%d\n", x);
}