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
const double EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 5, M = 4e4 + 5, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

int main() {
	Yahia74();
	double p;
	int n;
	while (cin >> n >> p) {
		cout << setiosflags(ios::fixed) << setprecision(0) << pow(p, 1.0 / n) << el;
	}
	return 0;
}
