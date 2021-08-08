#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;

pair<vector<int>, vector<int>> manacher(string s, bool front = 1, bool back = 1){
	if(front) s = "@"+s;
	if(back) s += "#";
	int n = (int)size(s);
	vector<int> p1(n), p2(n); //radii of palindromes (1 odd, 2 even length)
	
	for(int i = 1, mx = 0, p = 0; i < n-1; i++){
		p1[i] = (i >= mx) ? 1 : min(mx-i, p1[p*2-i]);
		while(s[i-p1[i]] == s[i+p1[i]])
			p1[i]++;
		if(i+p1[i] > mx)
			mx = i+p1[i], p = i;
	}
	for(int i = 1, mx = 0, p = 0; i < n-1; i++){
		p2[i] = (i >= mx) ? 0 : min(mx-i, p2[p*2-i+2]);
		while(s[i-p2[i]-1] == s[i+p2[i]])
			p2[i]++;
		if(i+p2[i] > mx)
			mx = i+p2[i], p = i-1;
	}
	if(front) p1.erase(p1.begin()), p2.erase(p2.begin());
	if(back) p1.pop_back(), p2.pop_back();
	return {p1, p2};
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	cin>>s;
	auto [a, b] = manacher(s);
	cout<<max(*max_element(all(a))*2-1, *max_element(all(b))*2)<<'\n';
}