#include <bits/stdc++.h>

using namespace std;

#define el      	"\n"
#define f 		first
#define mp(x,y)  	make_pair((x),(y))
#define pb(x)    	push_back((x))
#define all(v)  	((v).begin()),((v).end())
#define rall(v)	v.rbegin(),v.rend()
#define sz(x)  	((int) (x).size())
#define lp(i,n) 	for(int i=0;i<(int)n;i++)
#define setzero(a)	memset(a,0,sizeof(a))
#define setdp(a) 	memset(a,-1,sizeof(a))
#define bits(a) 	__builtin_popcountll(a)
typedef long long ll;
const double PI = 2 * acos(0.0), EPS = 1e-9;
const int INF = 1e9, NINF = -1e9, MOD = 1e9 + 7;

void GO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
#endif
	cout << fixed << setprecision(10);
	//ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
}

int dx[] = { 1, 1, -1, -1, 2, 2, -2, -2 };
int dy[] = { 2, -2, 2, -2, 1, -1, 1, -1 };

int d[10][10];

bool isValid(int r, int c) {
	return (r >= 0 & c >= 0 && r < 8 && c < 8);
}

int BFS(int sr, int sc, int tr, int tc) {
	memset(d, -1, sizeof(d));
	d[sr][sc] = 0;
	queue<int> q;
	q.push(sr);
	q.push(sc);
	while (!q.empty()) {
		int r = q.front();
		q.pop();
		int c = q.front();
		q.pop();
		if (r == tr && c == tc)
			return d[r][c];
		for (int k = 0; k < 8; k++) {
			int nr = r + dx[k];
			int nc = c + dy[k];
			if (!isValid(nr, nc))
				continue;
			if (d[nr][nc] == -1)
				d[nr][nc] = d[r][c] + 1, q.push(nr), q.push(nc);
		}
	}
	return -1;
}

char st[5], ed[5];
int main() {
	GO();
	while (scanf("%s%s", st, ed) != EOF) {
		int mov = BFS(st[1] - '1', st[0] - 'a', ed[1] - '1', ed[0] - 'a');
		printf("To get from %s to %s takes %d knight moves.\n", st, ed, mov);
	}
	return 0;
}
