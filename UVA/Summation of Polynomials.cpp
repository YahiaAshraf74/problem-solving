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
const int N = 5e4 + 2, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

ll ans[N] ;
int main() {
	Yahia74();
	for (int i = 1; i < N; ++i) {
		ans[i] =  (ll)i * i * i + ans[i-1];
	}
	int n ;
	while(cin>>n){
		cout << ans[n] << el;
	}
	return 0;
}
