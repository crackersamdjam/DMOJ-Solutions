#include <bits/extc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;

int n, cnt;
ll ans;
stack<int> stk;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	for(int i = 1; i <= n; i++){
		int a; cin>>a;
		while(cnt < a){
			ans += i-stk.top();
			stk.pop();
			cnt++;
		}
		if(a < cnt){
			ans += cnt-1-a;
			stk.emplace(i);
		}
		else{
			cnt++;
		}
		cout<<ans<<" \n"[i==n];
	}
}