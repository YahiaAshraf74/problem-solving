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
//	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

const int N = 1e3 + 5, M = 1e3 + 5, OO = 0x3f3f3f3f;
string s, s1;
int mem[N][N], tk = 1;
int solve(int i = 0, int j = 0) {
	if (i == sz(s) || j == sz(s1))
		return 0;
	int& ret = mem[i][j];
	if (ret == -1) {
		if (s[i] == s1[j])
			ret = solve(i + 1, j + 1) + 1;
		else
			ret = max(solve(i, j + 1), solve(i + 1, j));
	}
	return ret;
}

int main() {
	Yahia74();
	while (getline(cin, s), s[0] != '#') {
		getline(cin, s1);
		for (int i = 0; i < s.size(); ++i) {
			for (int j = 0; j < s1.size(); ++j) {
				mem[i][j] = -1;
			}
		}
		printf("Case #%d: you can visit at most %d cities.\n",tk++,solve());
	}
	return 0;
}
