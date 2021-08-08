#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
const int MM = 1005;

int n, m, rc, bc, yc;
string s;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>m>>n;
	while(n--){
		cin>>s;
		int r = 0, b = 0, y = 0;
		for(auto c: s){
			if(c == 'R' or c == 'O' or c == 'P' or c == 'B'){
				if(!r){
					r = 1;
					rc++;
				}
			}
			else{
				r = 0;
			}
			if(c == 'U' or c == 'G' or c == 'P' or c == 'B'){
				if(!b){
					b = 1;
					bc++;
				}
			}
			else{
				b = 0;
			}
			if(c == 'Y' or c == 'O' or c == 'G' or c == 'B'){
				if(!y){
					y = 1;
					yc++;
				}
			}
			else{
				y = 0;
			}
		}
	}
	cout<<rc<<' '<<yc<<' '<<bc<<'\n';
}