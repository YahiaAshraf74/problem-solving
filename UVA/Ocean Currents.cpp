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
const int N = 1e4 + 5, M = 1e5 + 74, OO = 0x3f3f3f3f;
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 },
		dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int n, m, q, dist[N][N];
bool vis[N][N];
char grid[N][N];
bool valid(int i, int j) {
	return i >= 0 && j >= 0 && i < n && j < m;
}
int bfs(pair<int, int> s, pair<int, int> d) {
	deque<pair<int, int>> q;
	q.push_back(s);
	dist[s.ft][s.sd] = 0;
	vis[s.ft][s.sd] = true;
	while (!q.empty()) {
		int sz = q.size();
		while (sz--) {
			int i = q.front().ft, j = q.front().sd;
			q.pop_front();
			if (i == d.ft && j == d.sd)
				return dist[i][j];
			for (int d = 0; d < 8; ++d) {
				int nx = i + dx[d], ny = j + dy[d];
				int plus = (d != grid[i][j] - '0') ? 1 : 0;
				if (valid(nx, ny) && !vis[nx][ny] && dist[nx][ny] > dist[i][j] + plus) {
					dist[nx][ny] = dist[i][j] + plus;
					if (!plus)
						q.push_front( { nx, ny });
					else
						q.push_back( { nx, ny });
				}
			}
		}
	}
}

int main() {
	Yahia74();
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> grid[i][j];
		}
	}
	cin >> q;
	while (q--) {
		clr(vis,false);
		clr(dist,OO);
		pair<int, int> st, ed;
		cin >> st.ft >> st.sd >> ed.ft >> ed.sd;
		--st.ft, --st.sd, --ed.ft, --ed.sd;
		cout << bfs(st, ed) << el;
	}
	return 0;
}
