#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
constexpr int MM = 2005;

int n, adj[MM][MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	cin>>n;
	for(int i = 2; i <= n; i++){
		string s;
		cin>>s;
		for(int j = 1; j < i; j++){
			adj[i][j] = adj[j][i] = (s[j-1] == 'B');
		}
	}
	
	for(int t = 1; t <= n; t++){
		int f = t%n+1, lc = -1, rc = -1;
		int l = f, r = f;
		deque<int> d;
		d.push_back(f);
		
		for(int i = 1; i <= n+1; i++){
			if(i == f or i == t)
				continue;
			if(i == n+1)
				i = t;
			
			if(rc == -1 or adj[r][i] == rc){
				rc = adj[r][i];
				d.push_back(i);
				r = i;
			}
			else if((lc == -1 and adj[i][l] != rc) or adj[i][l] == lc){
				//make sure lc doesn't get set same as rc
				lc = adj[i][l];
				d.push_front(i);
				l = i;
			}
			// can not i-r
			// but now check l-r
			// if l-r is lc, then can i-r-l
			// else it is rc and therefore can r-l-i
			else if(adj[l][r] == rc){
				d.push_back(l);
				d.push_back(i);
				r = i;
				
				d.pop_front();
				l = d.front();
			}
			else{
				d.push_front(r);
				d.push_front(i);
				l = i;
		
				d.pop_back();
				r = d.back();
			}
			
			if(i == t)
				break;
		}
		if(d.back() == t)
			reverse(all(d));
		
		cout<<n<<'\n';
		for(int i: d)
			cout<<i<<' ';
		cout<<'\n';
	}
}