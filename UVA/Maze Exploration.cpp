#include <bits/stdc++.h>

using namespace std;

#define el      	'\n'
#define ft 			first
#define sd 			second
#define mp(x,y)  	make_pair((x),(y))
#define pb(x)    	push_back((x))
#define all(v)  	((v).begin()),((v).end())
#define rall(v)		v.rbegin(),v.rend()
#define sz(x)  		((int) (x).size())
#define lp(i,n) 	for(int i=0;i<(int)n;i++)
#define lpv(i,a,n) 	for(int i=a;i<=(int)n;i++)
#define clr(a,b)	memset(a,b,sizeof(a))

typedef long long ll;

const double PI = 2 * acos(0.0), EPS = 1e-9;
const int INF = 1e9, NINF = -1e9, MOD = 1e9 + 7;
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 },
		dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
void GO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
#endif
	cout << fixed << setprecision(20);
	//ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

int T,  row;
char s[100][100];
void DFS(int i, int j) {
	if (s[i][j] == 'X' || s[i][j] == '#') return;
	s[i][j] = '#';
	DFS(i + 1, j); DFS(i - 1, j); DFS(i, j + 1); DFS(i, j - 1);
}
int main() {
	GO();
	cin >> T;
	cin.ignore() ;
	while (T--) {
		row = 0;
		while ( gets(s[row])  ){
			if (s[row][0] == '_') break;
			row++;
		}
		lp(i,row) for(int j = 0; s[i][j]; j++)  if (s[i][j] == '*') DFS(i, j);
		lp(i,row+1) puts(s[i]);
	}
	return 0;
}
