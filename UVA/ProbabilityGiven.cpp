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
const int N = 30, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

const int MAXN = 30;
int n, r;
bool vis[N] ;
double a[N], proPerson[N], totalPro;
void solve(int st, int taken) {
	if (taken == r) {
		double t = 1;
		for (int i = 0; i < n; i++)
			if (vis[i] == 1)
				t *= a[i];
			else
				t *= 1.0 - a[i];
		for (int i = 0; i < n; i++)
			if (vis[i])
				proPerson[i] += t;
		totalPro += t;
		return;
	}
	for (int i = st; i < n; i++) {
		vis[i] = true;
		solve(i + 1, taken + 1);
		vis[i] = false;
	}
}

int main() {
	Yahia74();
	int cases = 1;
	while (cin >> n >> r) {
		totalPro = 0;
		clr(vis, false);
		clr(proPerson, 0);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		solve(0, 0);
		cout << "Case " << cases++ << ":\n";
		for (int i = 0; i < n; i++)
			cout << proPerson[i] / totalPro << el;
	}
	return 0;
}
