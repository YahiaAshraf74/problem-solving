#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define lp(i,n) 	for(int i=0;i<(int)n;i++)
#define lpv(i,a,n) 	for(int i=a;i<=(int)n;i++)
#define sz(x)  		((int) (x).size())
void Yahia74() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
//	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(0);
}
const int N = 1e4 + 74, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

vector<pair<int, int>> adj[N];
bool vis[N];
int dis[N];
int numOfNodes;
void dijkstra(int from) {
	priority_queue<pair<int, int>, vector<pair<int, int>>,
			greater<pair<int, int>>> p;
	dis[from] = 0;
	p.push( { 0, from });
	while (!p.empty()) {
		int u = p.top().second, w = p.top().first;
		p.pop();
		if (w != dis[u])
			continue;
		for (int i = 0; i < (int) adj[u].size(); i++) {
			int v = adj[u][i].first, w2 = adj[u][i].second;
			int newCost = w + w2;
			if (dis[v] > newCost) {
				dis[v] = newCost;
				p.push( { newCost, v });
			}
		}
	}
}

int main() {
	Yahia74();
    ios::sync_with_stdio(false);
	int u, v, w;
	while (!cin.eof()) {
		clr(vis,false);
		clr(dis,OO);
		for(int i=0;i<N;i++)
			adj[i].clear();
		string s;
		getline(cin, s);
		while ((int)s.size() > 0 && !cin.eof()) {
			stringstream ss;
			ss << s;
			ss >> u >> v >> w;
			adj[u].push_back( { v, w });
			adj[v].push_back( { u, w });
			numOfNodes = max(numOfNodes, max(u, v));
			getline(cin, s);
		}
		dijkstra(u);
		int longestNode = 0, idxNode = 0;
		for (int i = 0; i <= N; i++) {
			if (dis[i] != OO) {
				if (dis[i] > longestNode) {
					longestNode = dis[i];
					idxNode = i;
				}
			}
			dis[i] = OO, vis[i] = false;
		}
		dijkstra(idxNode);
		for (int i = 0; i <= N; i++) {
			if (dis[i] != OO) {
				longestNode = max(longestNode, dis[i]);
			}
		}
		cout << longestNode << endl;
	}
	return 0;
}
