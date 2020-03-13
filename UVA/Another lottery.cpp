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
	int n ,m ;
	while(cin >> n >> m){
		if(!n && !m)
			break ;
		int S = 0 ;
		vector<int> v ;
		for(int i = 0 ; i< n*m;i++){
			int p ;
			cin >> p ;
			if(i%m == m-1){
				S += p ;
				v.pb(p) ;
			}
		}
		for(int i = 0 ; i < sz(v) ;i++){
			int g = __gcd(v[i] , S) ;
			cout << v[i]/g << " / " << S/g << el ;
		}
	}
	return 0;
}
