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
const double PI = acos(-1), EPS = 1e-9;

int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
char grid[10][10], color;
bool vis[10][10];
set<char> st;
int cnt;
bool valid(int i, int j) {
	return i >= 0 && i <= 8 && j >= 0 && j <= 8;
}
void dfs(int x, int y) {
	vis[x][y] = true;
	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d], ny = y + dy[d];
		if (valid(nx, ny)) {
			if (!vis[nx][ny]) {
				++cnt;
				dfs(nx, ny);
			} else if (grid[nx][ny] != '.') {
				st.insert(grid[nx][ny]);
			}
		}
	}
}
int main() {
	Yahia74();
	int T;
	cin >> T;
	while (T--) {
		int black = 0, white = 0;
		clr(vis, false);
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				cin >> grid[i][j];
				if (grid[i][j] == 'X')
					++black, vis[i][j] = true;
				else if (grid[i][j] == 'O')
					++white, vis[i][j] = true;
			}
		}
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (!vis[i][j]) {
					st.clear();
					cnt = 1;
					dfs(i, j);
					if (sz(st) == 1) {
						if (*(st.begin()) == 'X')
							black += cnt;
						else if (*(st.begin()) == 'O')
							white += cnt;
					}
				}
			}
		}
		cout << "Black " << black << " White " << white << el;
	}
	return 0;
}
