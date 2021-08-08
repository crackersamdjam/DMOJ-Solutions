#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;

string w = "кочерёг";

int main(){
	string s;
	cin>>s;
	int n = size(s);
	if(s[n-2] == '1'){
		cout<<s+" "+w+"\n";
	}
	else if(s[n-1] >= '2' and s[n-1] <= '4'){
		cout<<s<<" кочерги\n";
	}
	else if(s[n-1] == '1'){
		cout<<s<<" кочерга\n";
	}
	else{
		cout<<s+" "+w+"\n";
	}
}
// https://news.ycombinator.com/item?id=17164991
// of course I consult hacker news first
// https://unicode-org.github.io/cldr-staging/charts/38/supplemental/language_plural_rules.html