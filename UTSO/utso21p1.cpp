#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;

int n;

int main(){
	cin>>n;
	for(int s = 1; s <= n; s++){
		if(s%2 == 1){
			int l = s/2+1;
			if(2*l*l >= n){
				cout<<s<<'\n';
				break;
			}
		}
		else{
			int l = s/2;
			if(2*l*l + 2*l+1 >= n){
				cout<<s<<'\n';
				break;
			}
		}
	}
}