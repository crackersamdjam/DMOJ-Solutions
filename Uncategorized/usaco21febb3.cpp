#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int x = 0, y = 0, v = 0;
		for(auto c: s){
			if(c == 'E'){
				if(y > 0)
					v++;
				else if(y < 0)
					v--;
				x++;
			}
			else if(c == 'W'){
				if(y > 0)
					v--;
				else if(y < 0)
					v++;
				x--;
			}
			else if(c == 'N'){
				y++;
				if(x > 0)
					v--;
				else if(x < 0)
					v++;
			}
			else if(c == 'S'){
				y--;
				if(x > 0)
					v++;
				else if(x < 0)
					v--;
			}
		}
		if(v > 0)
			cout<<"CW\n";
		else
			cout<<"CCW\n";
	}
}