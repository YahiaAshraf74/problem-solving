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
int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int findlcm(int arr[], int n) {
	int ans = arr[0];
	for (int i = 1; i < n; i++)
		ans = (((arr[i] * ans)) / (gcd(arr[i], ans)));
	return ans;
}
int main() {
	GO();
	int n, t, len, mx, mn, lcm, cnt = 0, ans, ans1;
	while (cin >> n >> t && n && t) {
		vector<int> v(n);
		lp(i,n)
			cin >> v[i];
		while (t--) {
			cin >> len;
			mx = NINF, mn = INF;
			for (int i = 0; i < n; i++)
				for (int j = i + 1; j < n; j++)
					for (int k = j + 1; k < n; k++)
						for (int p = k + 1; p < n; p++) {
							if (i != j && i != k && i != p && j != k && j != p && k != p) {
								int arr[4] = { v[i], v[j], v[k], v[p] };
								lcm = findlcm(arr, 4);
								ans = 0, ans1 = 0;
								cnt++;
								while (ans <= len) {
									ans += lcm;
								}
								ans -= lcm;
								while (ans1 < len) {
									ans1 += lcm;
								}
								mx = max(mx, ans);
								mn = min(mn, ans1);
							}
						}
			cout << mx << " " << mn << el;
		}
	}
	return 0;
}
