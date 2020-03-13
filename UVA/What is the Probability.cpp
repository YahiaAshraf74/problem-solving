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

double power(double x, int y) {
	double res = 1;
	while (y > 0) {
		if (y & 1)
			res = (res * x);
		y = y >> 1;
		x = (x * x);
	}
	return res;
}
int main() {
	Yahia74();
	int t;
	cin >> t;
	while (t--) {
		int n, p;
		double d, d2;
		cin >> n >> d >> p;
		d2 = 1 - d;
		double sum = (power(d2, p-1) * d);
		for (int i = 0, k = p-1; i < 100; i++) {
			 k += n ;
			sum += (power(d2, k) * d);
		}
		cout <<fixed<< setprecision(4) << sum << el;
	}
	return 0;
}
