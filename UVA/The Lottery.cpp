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
ll lcm(ll a, ll b) {
	return (ll) a / __gcd(a, b) * b;
}

int a[16];
int main() {
	GO();
	int n, m;
	while (cin >> n >> m) {
		lp(i,m)
			cin >> a[i];
		int ans = 0, bits; ll l;
		lpv(i,1,(1<<m)){
			l = 1, bits = 0;
			lp(j,m)
				if (i & (1 << j))
					l = lcm(l, a[j]), bits++;
			(bits & 1) ? ans -= n / l : ans += n / l;
		}
		cout << ans << el;
	}
	return 0;
}
