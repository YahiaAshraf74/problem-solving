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
const int N = 1e6 + 74, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

int n;
vector<int> v[26];
int search(int block) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < sz(v[i]); j++) {
			if (v[i][j] == block)
				return i;
		}
	}
	return -1;
}
void removeAbove(int block, int pos) {
	while (!v[pos].empty()) {
		int top = v[pos].back();
		if (top == block)
			break;
		else {
			v[pos].pop_back();
			v[top].pb(top);
		}
	}
}
void movee(int f, int t, char c) {
	int p = search(f), p2 = search(t);
	if (p == p2)
		return;
	removeAbove(f, p);
	if (c == 'n')
		removeAbove(t, p2);
	v[p2].pb(f);
	v[p].pop_back();
}
void pile(int f, int t, char c) {
	int p = search(f), p2 = search(t);
	if (p == p2)
		return;
	if (c == 'n')
		removeAbove(t, p2);
	int idx;
	for (idx = 0; idx < sz(v[p]) && v[p][idx] != f; idx++)
		;
	move(v[p].begin() + idx, v[p].end(), back_inserter(v[p2]));
	v[p].erase(v[p].begin() + idx, v[p].end());
}
void print() {
	for (int i = 0; i < n; i++) {
		cout << i << ":";
		for (int j = 0; j < sz(v[i]); j++) {
			cout << ' ' << v[i][j];
		}
		cout << el;
	}
}
int main() {
	Yahia74();
	cin >> n;
	for (int i = 0; i < n; i++)
		v[i].pb(i);
	while (1 != 0) {
		string s, s1;
		int from, to;
		cin >> s;
		if (s[0] == 'q')
			break;
		cin >> from >> s1 >> to;
		if (s[0] == 'm') {
			movee(from, to, s1[1]);
		} else {
			pile(from, to, s1[1]);
		}
	}
	print();
	return 0;
}
/*






















 */
