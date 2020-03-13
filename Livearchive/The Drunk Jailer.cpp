#include <bits/stdc++.h>

using namespace std;

#define el      	"\n"
#define ft 			first
#define sd 			second
#define mp(x,y)  	make_pair((x),(y))
#define pb(x)    	push_back((x))
#define all(v)  	((v).begin()),((v).end())
#define rall(v)		v.rbegin(),v.rend()
#define sz(x)  		((int) (x).size())
#define lp(i,n) 	for(int i=0;i<(int)n;i++)
#define lpv(i,a,n) 	for(int i=a;i<(int)n;i++)
#define clr(a,b)	memset(a,b,sizeof(a))

typedef long long ll;
typedef unsigned long long ull;

const double PI = 2 * acos(0.0), EPS = 1e-9;
const int INF = 1e9, NINF = -1e9, MOD = 1e9 + 7;
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 },
		dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void GO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
#endif
	//cout << fixed << setprecision(2);
	ios::sync_with_stdio(NULL), cin.tie(NULL), cout.tie(NULL);
}
int main() {
	GO();
	int T ; cin >> T ;
	while (T-- ) {
		int n ,cnt = 0 ; cin >> n ;
		bool rm[105] ; clr(rm,1) ;
		for(int i=2;i<=n;i++){
				for(int j=i; j<=n; j=j+i)
						rm[j]= (rm[j] ^ 1) ;
		}
		for (int  i = 1 ; i <= n ; i++)
			if (rm[i]) ++cnt ;
		cout << cnt << el ;
	}
	return 0;
}
