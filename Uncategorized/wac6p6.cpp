#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
constexpr int TOT = 100, LIM = 43;

int n, T;
int mp[200];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	mp['R'] = 0, mp['G'] = 1, mp['B'] = 2;
	cin>>T;
	while(T--){
		vector<int> cnt(3), in(3), on(3), v(3);
		iota(all(on), 0);
		cin>>v[0]>>v[1]>>v[2];
		sort(all(v));
		int good = v[0]+v[1] >= 43;

		for(int i = 1; i <= TOT; i++){
			char s; cin>>s; s = mp[s];
			cnt[s]++;
			int a = min_element(all(cnt))-cnt.begin();
			int c = max_element(all(cnt))-cnt.begin();
			if(c == a)
				c = (a+1)%3;
			int b = 3-a-c;

			int remc = v[2]-cnt[c]+in[on[c]];
			int remb = v[1]-cnt[b]+in[on[b]];
			int rema = v[0]-cnt[a]+in[on[a]];

			if(not good and cnt[c] > v[0]){
				if(rema > remb)
					swap(a, b);

				if(not on[c] and on[a]){
					cout<<"EMPTY "<<on[a]<<endl;
					in[on[a]] = 0;
					on[c] = on[a];
					on[a] = 0;
				}
				else{
					swap(b, c);
					if(not on[c] and on[a]){
						cout<<"EMPTY "<<on[a]<<endl;
						in[on[a]] = 0;
						on[c] = on[a];
						on[a] = 0;
					}
				}
			}

			if(on[s]){
				cout<<"PLACE "<<on[s]<<endl;
				in[on[s]]++;
			}
			else{
				cout<<"DISCARD"<<endl;
			}
		}
	}
}