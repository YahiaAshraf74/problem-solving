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
bool primes[10000074];
int main() {
	GO();
	primes[0] = 1, primes[1] = 1;
	for (int i = 2; i * i <= 10000000; i++) {
		if (primes[i])
			continue;
		for (int j = i * i; j <= 10000000; j += i)
			primes[j] = true;
	}
	int n;
	while (cin >> n) {
		if (n < 8)
			cout << "Impossible.\n";
		else {
			int ans[4] = { 0 }, m = n;
			for (int i = n - 6; i >= 0; i--) {
				if (!primes[i]) {
					ans[0] = i;
					n -= i;
					break;
				}
			}
			for (int i = n - 4; i >= 0; i--) {
				if (!primes[i]) {
					ans[1] = i;
					n -= i;
					break;
				}
			}
			for (int i = n - 2; i >= 0; i--) {
				if (!primes[i]) {
					ans[2] = i;
					ans[3] = m - (ans[0] + ans[1] + ans[2]);
					n -= i;
					break;
				}
			}
			lp(i,4)
				cout << ans[i] << " \n"[i == 3];

		}
	}
	return 0;
}
