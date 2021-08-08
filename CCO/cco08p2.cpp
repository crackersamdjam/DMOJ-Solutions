#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 4e5+5;

map<string, int> mp;
int t, n, m, par[MM*2];

int find(int x){
	while(x != par[x])
		x = par[x], par[x] = par[par[x]];
	return x;
}

void merge(int a, int b){
	a = find(a), b = find(b);
	par[a] = b;
}

int id(string s){
	return mp[s] ? mp[s] : mp[s] = ++t;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	iota(par, par+MM*2, 0);
	cin>>n>>m;
	while(n--){
		string sa, sb, s;
		cin>>sa>>sb>>s;
		int a = id(sa), b = id(sb);

		if(s == "parallel"){
			merge(a, b);
			merge(a+MM, b+MM);
		}
		else{
			assert(a != b);
			merge(a, b+MM);
			merge(b, a+MM);
		}
	}
	for(int i = 1; i <= t; i++){
		if(find(i) == find(i+MM)){
			cout<<"Waterloo\n";
			return 0;
		}
	}
	while(m--){
		string sa, sb;
		cin>>sa>>sb;
		int a = id(sa), b = id(sb);
		if(find(a) == find(b)){
			cout<<"parallel\n";
		}
		else if(find(a) == find(b+MM)){
			cout<<"intersect\n";
		}
		else{
			cout<<"unknown\n";
		}
	}
}