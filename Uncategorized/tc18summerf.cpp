#include <bits/stdc++.h>
#define MM 1000002
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){
    string first, second;
    cin >> first;
    cin >> second;
    first.erase(0, first.find_first_not_of('0'));
    second.erase(0, second.find_first_not_of('0'));
    if (first.length() > second.length()){
        printf("S\n");
        return 0;
    }else if (first.length() < second.length()){
        printf("T\n");
        return 0;
    }
    for (int i = 0; i < max(first.length(), second.length()); i++){
        if (first[i] - '0' > second[i] - '0'){
            printf("S\n");
            return 0;
        }else if (first[i] - '0' < second[i] - '0'){
            printf("T\n");
            return 0;
        }
    }
    printf("E\n");
    return 0;
}