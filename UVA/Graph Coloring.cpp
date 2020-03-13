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
	freopen("input.txt", "r", stdin);  freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

int T , n , m , x , y  , black , mx ;
vector <int > adj[105]  , ans ;
bool vis[105] , colred[105];

void backTrack(int node , int cnt ){
	if (node == n+1){
		if (mx < cnt){
			mx = cnt ;
			ans.clear() ;
			lpv(i,1,n)
				if (colred[i] == true )
					ans.pb(i)  ;
		}
	}else {
		backTrack(node+1,cnt) ;
		if (colred[node] == false ){
			lp(j,sz(adj[node])){
				if (colred[adj[node][j]] == true ){
					return ;
				}
			}
			colred[node] = true ;
			backTrack(node+1 , cnt+1) ;
			colred[node] = false ;
		}
	}
}
int main() {
	Yahia74();
	cin >> T ;
	while (T--){
		cin >> n >> m ;
		lp(i,105) adj[i].clear() ;
		mx = 0 ;
		while(m--){
			cin >> x >> y ;
			adj[x].pb(y) ;
			adj[y].pb(x) ;
		}
		backTrack(1,0) ;
		cout << mx << el ;
		lp(i,sz(ans))
			cout << ans[i] << " \n"[i==sz(ans)-1] ;

 	}
	return 0;
}
