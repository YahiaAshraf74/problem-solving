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
const int N = 1e2 + 74, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

int m, w, c;
double cmb[N][N];
int main() {
	Yahia74();
	for (int i = 0; i <= 100; i++)
		cmb[i][0] = 1;
	for (int i = 1; i <= 100; i++)
		for (int j = 1; j <= i; j++)
			cmb[i][j] = cmb[i - 1][j] + cmb[i - 1][j - 1];
	while (cin >> m >> w >> c) {
		if (!m && !w)
			break;
		double pm = (m + 0.0) / (m + w) , pw = 1 - pm , ans = 0.0;
		for (int i = 0; i <= c; i += 2)
			ans += cmb[c][i] * pow(pm, i) * pow(pw, c - i);
		cout << fixed << setprecision(7) << ans << el ;
	}
	return 0;
}
