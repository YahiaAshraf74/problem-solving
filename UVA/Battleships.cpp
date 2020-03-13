// TTTY.cpp
// Created on: Apr 14, 2018
// Author: Yahia Asharf

#include <bits/stdc++.h>

using namespace std;

#define el      	 "\n"
#define f 			first
#define s 			second
#define mp(x,y)  	make_pair((x),(y))
#define pb(x)    	push_back((x))
#define all(v)  	((v).begin()),((v).end())
#define rall(v)		v.rbegin(),v.rend()
#define sz(x)  		((int) (x).size())
#define fl(i,n) 	for(i=0;i<n;i++)
#define setzero(a)	memset(a,0,sizeof(a))
#define setdp(a) 	memset(a,-1,sizeof(a))
#define bits(a) 	__builtin_popcountll(a)

typedef long long ll;
typedef long double ld;
typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef map<long, long> mll;
typedef set<int> si;
typedef set<string> sst;
typedef set<long> sl;

const double PI = 2 * acos(0.0);
const double EPS = 1e-9;
const int INF = 1e9;
const int NINF = -1e9;
const int MOD = 1e9 + 7;

int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

ll gcd(ll a, ll b) {
	return !b ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return (a / gcd(a, b)) * b;
}

void PLAY() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	cout << fixed << setprecision(10);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int n;
char grid[100][101];
bool vis[100][100];

bool valid(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < n;
}

void DFS(int i, int j) {
	if ((grid[i][j] == '.' || vis[i][j]) || !valid(i, j))
		return;
	vis[i][j] = true;
	DFS(i - 1, j);
	DFS(i + 1, j);
	DFS(i, j - 1);
	DFS(i, j + 1);
}

int main() {
	PLAY();
	int t, ans, C = 0;
	cin >> t;
	while (t--) {
		C++;
		ans = 0;
		memset(vis, 0, sizeof vis);
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> grid[i][j];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (!vis[i][j] && grid[i][j] == 'x') {
					ans++;
					DFS(i, j);
				}
		cout << "Case " << C << ": " << ans << el ;
	}

	return 0;
}
