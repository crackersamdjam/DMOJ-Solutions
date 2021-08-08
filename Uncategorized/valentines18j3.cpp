#include <bits/stdc++.h>
using namespace std;
#define MM 10002
#define f first
#define s second
string names[MM];
pair<int,int> arr[MM];
bool cute[MM];
int main() {
    int N; cin >> N;
    for(int i = 0; i < N; i++){
        cin >> names[i];
        cin >> arr[i].f;
        arr[i].s = i;
    }
    sort(arr, arr+N);
    for(int i = ceil(N/2)+1; i < N; i++){
        cute[arr[i].s] = true;
    }
    for(int i = 0; i < N; i++){
        cute[i] ? cout << names[i] << "  is cute! <3\n":
        cout << names[i] << "is not cute. </3\n";
    }
    return 0;
}