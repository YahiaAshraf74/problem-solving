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
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	cout << fixed << setprecision(10);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

char grid[30][30];
bool seen[30][30];
int n, cnt;

bool valid(int i, int j) {
	return i >= 0 && j >= 0 && i < n && j < n;
}

void DFS(int r, int c) {
	if (!valid(r, c) || seen[r][c] == true)
		return;
	seen[r][c] = 1 ;
	for (int i = 0; i < 8; i++) {
		int nr = r + dx[i];
		int nc = c + dy[i];
		if( !seen[nr][nc] && grid[nr][nc] == '1')
			DFS(nr,nc);

	}
}

int main() {
	PLAY();
	int s = 0;
	while (cin >> n) {
		++s;
		setzero(seen);
		int res = 0;
		for (int i = 0; i < n; i++)
				cin >> grid[i];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (!seen[i][j] && grid[i][j] == '1') {
					DFS(i, j);
					res++;
				}
			}
		cout << "Image number " << s << " contains " << res << " war eagles."<< el;
	}
	return 0;
}
