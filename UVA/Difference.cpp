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
	//ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
vector<int> adj[505], adj1[505];
int nodes, edges, query,testCase, x , y , node , mn, mx,totalTime, timee[505];
bool vis[505] ;
void dfs(int n) {
	if (vis[n])
		return;
	vis[n] = 1;
	mn += timee[n] ;
	lp(i, sz(adj[n])){
		if (!vis[adj[n][i]])
			dfs(adj[n][i]) ;
	}
}
void dfs1(int n) {
	if (vis[n])
		return;
	vis[n] = 1;
	mx += timee[n] ;
	lp(i, sz(adj1[n])){
		if (!vis[adj1[n][i]])
			dfs1(adj1[n][i]) ;
	}
}
int main() {
	YAHIA();
	while (cin >> nodes >> edges)  {
		if ( !(nodes + edges) ) break ;
		clr(timee, 0);
		totalTime = 0 ;
		lpv(i,1,nodes){
			cin >> timee[i];
			totalTime += timee[i] ;
			adj[i].clear() ;
			adj1[i].clear();
		}
		lp(i,edges){
			cin >> x >> y;
			adj[x].pb(y);
			adj1[y].pb(x);
		}
		cin >> query;
		cout << "Case #" << ++testCase << ":" << el;
		lp(i,query){
			cin >> node;
			mn = 0 , mx = 0 ;
			clr(vis,0) ;
			dfs(node) ;
			clr(vis,0) ;
			dfs1(node) ;
			cout << totalTime - mx - (mn-timee[node])  << el ;
		}
		cout << el ;
	}
	return 0;
}
