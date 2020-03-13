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
	freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

const int N = 1e4 + 74, M = 1e5 + 74, OO = 0x3f3f3f3f;
vector<pair<string, int> > binTree;
string node;
pair<string, int> getValue(string s) {
	pair<string, int> val = { "", 0 };
	int num = 0;
	string dir = "";
	lpv(i,1,sz(s)-2)
	{
		if (s[i] >= '0' && s[i] <= '9') {
			num = num * 10 + s[i] - '0';
		} else if (s[i] == ',') {
			val.sd = num;
		} else {
			dir += s[i];
		}
	}
	if (dir == "")
		dir = "A";
	val.ft = dir;
	return val;
}
bool cmp(pair<string, int> s1, pair<string, int> s2) {
	if (sz(s1.ft) == sz(s2.ft))
		return s1 < s2;
	else
		return sz(s1.ft) < sz(s2.ft);
}
bool find(string s) {
	if (sz(s) == 1)
		return true;
	s.pop_back();
	for (int i = 0; i < sz(binTree); i++) {
		if (s == binTree[i].ft)
			return find(binTree[i].ft);
	}
	return false;
}
int main() {
	Yahia74();
	while (cin >> node) {
		binTree.clear();
		bool ok = false;
		pair<string, int> temp = getValue(node);
		if (temp.ft == "A")
			ok = true;
		binTree.pb(temp);
		while (cin >> node) {
			if (node == "()")
				break;
			temp = getValue(node);
			if (temp.ft == "A")
				ok = true;
			binTree.pb(temp);
		}
		sort(all(binTree), cmp);
		for (int i = sz(binTree) - 1; i > 0; i--) {
			if (!find(binTree[i].ft) || (binTree[i].ft == binTree[i - 1].ft) ) {
				ok = false;
				break;
			}
		}
		if (!ok) {
			cout << "not complete\n";
		} else {
			lp(i,sz(binTree))
				cout << binTree[i].sd << " \n"[i == sz(binTree) - 1];
		}

	}
	return 0;
}
