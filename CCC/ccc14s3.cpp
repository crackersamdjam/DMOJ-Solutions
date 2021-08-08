#include <bits/stdc++.h>
using namespace std;
int T,N,M;
int main(){
  scanf("%d",&T);
  for (int i=0;i<T;i++){
    int counter=1;
    stack <int> mountain;
    stack <int> branch; 
    scanf("%d",&N);
    for (int i=0;i<N;i++){
      scanf("%d",&M);
      mountain.push(M);
    }
    while (!mountain.empty()){
      if (mountain.top()==counter){
        mountain.pop();
        counter++;
      }
      else if (!branch.empty()&&branch.top()==counter){
        branch.pop();
        counter++;
      }
      else{
        branch.push(mountain.top());
        mountain.pop();
      }
    }
    bool memed=false;
    while (!branch.empty()){
      if (branch.top()==counter){
        branch.pop();
        counter++;
      }
      else{
        memed=true;
        break;
      }
    }
    printf(memed? "N\n" : "Y\n");
  }
}