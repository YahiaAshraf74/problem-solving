#include <bits/stdc++.h>
using namespace std;
#define el      	'\n'
#define ft 			first
#define sd 			second
#define mp(x,y)  	make_pair((x),(y))
#define pb(x)    	push_back((x))
#define all(v)  	((v).begin()),((v).end())
#define sz(x)  		((int) (x).size())
#define clr(a,b)	memset(a,b,sizeof(a))
typedef long long ll;
void Yahia74() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
const int N = 1e5 + 74, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

int main() {
	Yahia74();
	int T ;
	cin >> T ;
	while(T--){
		ll s ,d ;
		cin >> s >> d ;
		if(d>s){
			cout << "impossible\n";
			continue ;
		}
		ll y = (ll)(s - d)/2 ;
		ll x  = (ll)(s - y) ;
		if(y < 0 || x < 0 || x+y!=s || abs(x-y)!=d ){
			cout << "impossible\n";
		}else{
			cout << max(x,y) << ' ' << min(x,y) << el ;
		}
	}
	return 0;
}
