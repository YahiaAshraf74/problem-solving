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
const int N = 5e2 + 74, M = 1e5 + 74, OO = 0x3f3f3f3f;

int stand[N] , adjMat[N][N] , inDgree[N] ;
vector<int> ans ;
int main() {
	Yahia74();
	int T ;
	cin >> T ;
	while(T--){
		clr(adjMat,0) ;
		ans.clear() ;
		int n , m ;
		cin >> n  ;
		lp(i,n) cin >> stand[i] ;
		lp(i,n){
			for (int j = i + 1; j < n; ++j) {
				adjMat[stand[i]][stand[j]] = true ;
 			}
		}
		cin >> m ;
		lp(i,m){
			int u , v ;
			cin >> u >> v ;
			swap(adjMat[u][v],adjMat[v][u]);
		}
		lpv(i,1,n){
			inDgree[i] = 0 ;
			for (int j = 1; j <= n; ++j) {
				inDgree[i] += adjMat[j][i] ;
			}
		}
		queue<int> q ;
		lpv(i,1,n){
			if (!inDgree[i]){
				q.push(i) ;
			}
		}
		while(!q.empty()){
			int sz = q.size() ;
			while(sz--){
				int u = q.front() ;
				q.pop() ;
				ans.pb(u) ;
				lpv(i,1,n){
					if (!--inDgree[i] && adjMat[u][i] ){
						q.push(i);
					}
				}
			}
		}
		if (sz(ans) != n){
			cout << "IMPOSSIBLE\n"  ;
		}else{
			lp(i,sz(ans)) cout << ans[i] << " \n"[i==sz(ans)-1] ;
		}
	}
	return 0;
}
