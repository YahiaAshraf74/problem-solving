#include <bits/stdc++.h>

using namespace std;

#define el      	'\n'
#define ft 			first
#define sd 			second
#define mp(x,y)  	make_pair((x),(y))
#define pb(x)    	push_back((x))
#define all(v)  	((v).begin()),((v).end())
#define rall(v)		v.rbegin(),v.rend()
#define sz(x)  		((int) (x).size())
#define lp(i,n) 	for(int i=0;i<(int)n;i++)
#define lpv(i,a,n) 	for(int i=a;i<=(int)n;i++)
#define clr(a,b)	memset(a,b,sizeof(a))

typedef long long ll;

const double PI = 2 * acos(0.0), EPS = 1e-9;
const int INF = 1e9, NINF = -1e9, MOD = 1e9 + 7;
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 },
		dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
void GO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
#endif
	cout << fixed << setprecision(20);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
int hi[10001] , l, r, buildingHi , currentHi ;
int main() {
	GO();
	while (cin >> l >> buildingHi >> r)
		for (int i = l; i < r; ++i)
			hi[i] = max(hi[i] , buildingHi ) ;
	lp(i,10000) if (hi[i] != currentHi) {
			cout << i << ' ' << hi[i] ;
			currentHi = hi[i];
		}
	cout << el;
	return 0;
}
