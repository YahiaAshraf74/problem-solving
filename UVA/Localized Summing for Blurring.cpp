#include <bits/stdc++.h>

using namespace std;

#define el      	"\n"
#define ft 			first
#define sd 			second
#define mp(x,y)  	make_pair((x),(y))
#define pb(x)    	push_back((x))
#define all(v)  	((v).begin()),((v).end())
#define rall(v)		v.rbegin(),v.rend()
#define sz(x)  		((int) (x).size())
#define lp(i,n) 	for(int i=0;i<(int)n;i++)
#define lpv(i,a,n) 	for(int i=a;i<(int)n;i++)
#define clr(a,b)	memset(a,b,sizeof(a))

typedef long long ll;
typedef unsigned long long ull;

const double PI = 2 * acos(0.0), EPS = 1e-9;
const int INF = 1e9, NINF = -1e9, MOD = 1e9 + 7;
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 },
		dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void GO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
#endif
	//cout << fixed << setprecision(2);
	ios::sync_with_stdio(NULL), cin.tie(NULL), cout.tie(NULL);
}
int sum2D[1005][1005];
int main() {
	GO();
	int n, m, newSum2D , cell ;
	ll ans;
	bool f = 0 ;
	while (cin >> n >> m) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cin >> sum2D[i][j];

		for (int i = 0; i <= n; i++)
			sum2D[i][0] = sum2D[0][i] = 0;

//		for (int i = 1; i <= n; i++)
//			for (int j = 1; j <= n; j++)
//				sum2D[i][j] = sum2D[i - 1][j] + sum2D[i][j - 1] - sum2D[i - 1][j - 1] + sum2D[i][j];
	    for (int i = 1; i <= n; i++)
	      for (int j = 1; j <= n; j++)
	    	  sum2D[i][j] += sum2D[i][j-1];

	    for (int j = 1; j <= n; j++)
	      for (int i = 1; i <= n; i++)
	    	  sum2D[i][j] += sum2D[i-1][j];
		if(f)cout << el , f = 0 ;
		newSum2D = n - m + 1;
		ans = 0;
		for (int i = 1; i <= newSum2D; i++)
			for (int j = 1; j <= newSum2D; j++)
				cell = sum2D[i + m - 1][j + m - 1] - sum2D[i - 1][j + m - 1] - sum2D[i + m - 1][j - 1] + sum2D[i - 1][j - 1],
				cout << cell << el,
				ans += (ll) cell;


		cout << ans << el  ;
		f=1 ;
	}
	return 0;
}
