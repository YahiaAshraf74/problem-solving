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
//	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
const int N = 1e5 + 74, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;
const double PI = acos(-1), EPS = 1e-9;

vector<int> adj[21], nodes;
set<vector<int>> ans;
int in[21];
void bfs(bool v[], vector<int> p) {
	if (sz(p) == sz(nodes))
		ans.insert(p);
	for (int i = 0; i < sz(nodes); ++i) {
		if (in[nodes[i]] == 0 && !v[nodes[i]]) {
			for (int j = 0; j < sz(adj[nodes[i]]); j++)
				in[adj[nodes[i]][j]]--;
			v[nodes[i]] = true;
			p.pb(nodes[i]);
			bfs(v, p);
			v[nodes[i]] = false;
			p.pop_back();
			for (int j = 0; j < sz(adj[nodes[i]]); j++)
				in[adj[nodes[i]][j]]++;
		}
	}
}
int main() {
	Yahia74();
	int T;
	cin >> T;
	cin.ignore();
	while (T--) {
		cin.ignore();
		string line;
		getline(cin, line);
		for (int i = 0; i < sz(line); i++)
			if (line[i] != ' ')
				nodes.pb(line[i]-'A');
		string line2;
		getline(cin, line2);
		for (int i = 0; i < sz(line2); i++)
			if (line2[i] != ' ')
				adj[line2[i] - 'A'].pb(line2[i+2]-'A'), ++++i;
		bool v[21] = { };
		vector<int> p;
		for (int i = 0; i < sz(nodes); ++i)
			for (int j = 0; j < sz(adj[nodes[i]]); j++)
				in[adj[nodes[i]][j]]++;
		bfs(v, p);
		if (!sz(ans))
			cout << "NO" << el;
		for (auto p : ans) {
			for (auto c : p) {
				cout << (char) (c + 'A');
				if (c != p.back())
					cout << ' ';
			}
			cout << el;
		}
		if (T)
			cout << el;
		ans.clear();
		nodes.clear();
		clr(in, 0);
		for (int i = 0; i < 21; ++i)
			adj[i].clear();
	}
	return 0;
}
