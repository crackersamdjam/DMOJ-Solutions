#include <iostream>
using namespace std;
int main() {
    printf("guess -50\n");
    fflush(stdout);
    int n;
    scanf("%d",&n);
    printf("answer %d\n",n-50);
    fflush(stdout);
    return 0;
}