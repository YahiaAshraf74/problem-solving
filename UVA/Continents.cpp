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

void YAHIA() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
#endif
	cout << fixed << setprecision(8);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
int dx[8] = { 0, 0, -1, 1 }, dy[8] = { 1, -1, 0, 0 };
int n, m, x, y, cnt, mx;
bool vis[21][21];
string grid[21];
bool valid(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m;
}

void flodFill(int i, int j) {
	if (!valid(i, j) || grid[i][j] == '0' || vis[i][j])
		return;
	vis[i][j] = 1;
	++cnt;
	lp(k,4)
		flodFill(i + dx[k], j + dy[k]);
	if (j == 0 && (grid[i][j] == grid[i][m - 1]))
		flodFill(i, m - 1);
	if (j == m - 1 && (grid[i][j] == grid[i][m - 1]))
		flodFill(i, 0);
	return;
}
int main() {
	YAHIA();
	while (cin >> n >> m) {
		clr(vis, 0);
		mx = 0 ,cnt = 0 ;
		lp(i,n)
			cin >> grid[i];
		cin >> x >> y;
		char comp = grid[x][y] ;
		lp(i,n)
			lp(j,m)
				if (grid[i][j] == comp)
					grid[i][j] = '1';
				else
					grid[i][j] = '0';
		flodFill(x, y);
		lp(i,n)
			lp(j,m){
				cnt = 0;
				if (grid[i][j] == '1' && !vis[i][j]) {
					flodFill(i, j);
					mx = max(mx, cnt);
				}
			}
		cout << mx << el;
	}
	return 0;
}
