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
const int N = 5e4 + 2, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

//long long power(long long base, long long power) {
//	long long res = 0;
//	while (power) {
//		if (power & 1)
//			res = (res + base) ;
//		base = (base + base) ;
//		power >>= 1;
//	}
//	return res;
//}
long long power(int x, int n) {
    long long ret = 1;
    while (n--)
        ret *= x;
    return ret;
}

int main() {
	Yahia74();
	string line;
	istringstream sin;
	while (getline(cin, line)) {
		sin.clear();
		sin.str(line);
		vector<int> coff, x;
		int num;
		while (sin >> num)
			coff.pb(num);
		getline(cin, line);
		sin.clear();
		sin.str(line);
		while (sin >> num)
			x.pb(num);
		for (int i = 0; i < sz(x); i++) {
			if (i != 0) cout << " ";
			ll sum = 0;
			for (int j = 0; j < sz(coff); j++)
				sum += coff[j] * power(x[i], sz(coff)- j - 1);
			cout << sum;
		}
		cout<< el ;
	}
	return 0;
}
