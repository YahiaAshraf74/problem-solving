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
const int N = 1e3 + 74, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

vector<pair<int, int> > adj[N];
int main() {
	Yahia74();
	int T;
	cin >> T;
	while (T--) {
		int com, budget;
		int numOfComp = 1;
		map<string, int> mp;
		cin >> com >> budget;
		for (int i = 0; i <= 1004; ++i)
			adj[i].clear();
		for (int i = 0; i < com; ++i) {
			string s, t;
			int quality, price;
			cin >> s >> t >> price >> quality;
			if (mp.find(s) == mp.end())
				mp[s] = numOfComp++;
			adj[mp[s]].pb(mp(price,quality));
		}
		for (int i = 1; i < numOfComp; i++) {
			sort(all(adj[i])); // sorting in price order then quality
			for (int j = 1; j < sz(adj[i]); j++) {
				while (adj[i][j].sd <= adj[i][j - 1].sd && j < sz(adj[i]))
					adj[i].erase(adj[i].begin() + j); // erase all unsafely components that have higher price with lower quality
			}
		}
		set<int> totQ ;
		for (int i = 1; i < numOfComp; i++)
			for (int j = 0; j < sz(adj[i]); j++)
				totQ.insert(adj[i][j].sd);
		int idx[1005]={}; // pointer in each components refer to current quality so far.
		int ans = -1;
		bool flag = false;
		for (auto i : totQ) {
			ll tot = 0;
			for (int j = 1; j < numOfComp; j++) {
				while (adj[j][idx[j]].sd < i && idx[j] < sz(adj[j]))
					idx[j]++;
				if (idx[j] == sz(adj[j])) { // break if I reach the end of any components because that is the maximum I will get
					flag = true;
					break;
				}
				tot += (ll) adj[j][idx[j]].ft;
			}
			if (tot > budget || flag)
				break;
			ans = i;
		}
		cout << ans << el;
	}
	return 0;
}
/*























 */
