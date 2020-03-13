#include <bits/stdc++.h>
using namespace std;
#define el      	'\n'
#define ft 			first
#define sd 			second
#define mp(x,y)  	make_pair((x),(y))
#define pb(x)    	push_back((x))
#define all(v)  	((v).begin()),((v).end())
#define sz(x)  		((int) (x).size())
#define lp(i,n) 	for(int i=0;i<(int)n;i++)
#define lpv(i,a,n) 	for(int i=a;i<=(int)n;i++)
#define clr(a,b)	memset(a,b,sizeof(a))
typedef long long ll;
void Yahia74() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin); //freopen("output.in", "w", stdout);
#endif
//	cout << fixed << setprecision(8);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

const int N = 1e4 + 5, M = 1e3 + 5, OO = 0x3f3f3f3f;

int n, T, mem[N][N];
vector<int> vec;
int solve(int i = 0, int prev = sz(vec)) {
	if (i == sz(vec))
		return 0;
	int& ret = mem[i][prev];
	if (~ret)
		return ret;
	return ret = max(solve(i + 1, prev),
			vec[i] > vec[prev] ? solve(i + 1, i) + 1 : 0);
}
void build(int i = 0, int prev = sz(vec)) {
	if (i == sz(vec))
		return;
	if (solve(i, prev) == solve(i + 1, prev))
		build(i + 1, prev);
	else {
		cout << vec[i] << el;
		build(i + 1, i);
	}
}

int main() {
	Yahia74();
	cin >> T;
	string sep = "";
	while (T--) {
		vec.clear();
		clr(mem,-1);
		cin >> n;
		vec.pb(n);
		cin.ignore();
		while (cin.peek() >= '0' && cin.peek() <= '9')
			cin >> n, vec.pb(n), cin.ignore();
		cout << sep << "Max hits: " << solve() << '\n';
		sep = "\n";
		build();
	}
	return 0;
}
