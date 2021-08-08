#include <bits/stdc++.h>
using namespace std;
int main() {
    unsigned long long n;
    scanf("%lu", &n);
    unsigned long long arr[n];
    scanf("%lu", &arr[0]);
    for(int i = 1; i < n; i++){
        scanf("%lu", &arr[i]);
        arr[i] += arr[i-1];
    }
    unsigned long long a[n];
    a[0] = arr[0];
    for(int i = 1; i < n; i++){
        a[i] = arr[i] + a[i-1];
    }
    stack<unsigned long long> st;
    st.push(arr[n-1]);
    printf("%lu\n", arr[n-1]);
    for(int i = 2; i <= (n+1)/2; i++){
        unsigned long long sum = a[n-1] - a[n-1-i] - a[i-2];
        if(n-i >= i) st.push(sum);
        printf("%lu\n", sum);
    }
    while(!st.empty()){
        printf("%lu\n", st.top());
        st.pop();
    }
    return 0;
}