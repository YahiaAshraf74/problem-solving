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
	freopen("input.txt", "r", stdin);  //freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

vector<pair<double, pair<int, int>> > edges;
vector <pair <int ,int > > towns ,ans ;
int T, n, m, x , y, from, to, par[774], sz[774];
struct disJoint {
	int connComp, sizeOfDisJoint;
	disJoint(int size) {
		connComp = sizeOfDisJoint = size;
		for (int i = 0; i < size; i++)
			par[i] = i, sz[i] = 1;
	}
public:
	int find(int node) {
		int root = node;
		while (root != par[root])
			root = par[root];
		while (node != root) {
			int next = par[node];
			par[node] = root;
			node = next;
		}
		return root;
	}
	bool unionSet(int node1, int node2) {
		int root1 = find(node1), root2 = find(node2);
		if (root1 == root2)
			return 0;
		else if (sz[root1] > sz[root2]) {
			sz[root1] += sz[root2];
			par[root2] = root1;
		} else {
			sz[root2] += sz[root1];
			par[root1] = root2;
		}
		--connComp;
		return 1;
	}
	int numOfConnComp() {
		return connComp;
	}
	bool connected(int node1, int node2) {
		return find(node1) == find(node2);
	}
	int componentSize(int node) {
		return sz[find(node)];
	}
	int size() {
		return sizeOfDisJoint;
	}
};
double getDistance(pair <int,int> p , pair<int ,int > p1){
    return abs (sqrt( abs((p.ft - p1.ft) * (p.ft - p1.ft)) + abs((p.sd-p1.sd) *(p.sd-p1.sd) )));
}

int main() {
	YAHIA();
	cin >> T;
	lpv(tc,1,T){
		cin >> n ;
		clr(sz,0) ;
		clr(par,0) ;
		disJoint d1(n);
		edges.clear();
		towns.clear() ;
		ans.clear() ;
		lp(i,n){
			cin >> x >> y ;
			towns.pb(mp(x,y)) ;
		}
		cin >> m ;
		lp(i,m){
			cin >> from >> to ;
			d1.unionSet(from,to) ;
		}
		lpv(i,1,n){
			lpv(j,i+1,n){
				edges.pb(mp(getDistance(towns[i-1],towns[j-1]) ,mp(i,j)));
			}
		}
		sort(all(edges)) ;
		for (auto edge : edges){
			if (d1.unionSet(edge.sd.ft , edge.sd.sd)){
				ans.pb(mp(edge.sd.ft,edge.sd.sd)) ;
				if (d1.componentSize(edge.sd.ft) >= n) break ;
			}
		}
		if (tc !=1)cout << el ;
		if (!sz(ans))
			cout << "No new highways need" << el ;
		else
			lp(i,sz(ans))
				cout << ans[i].ft << " " << ans[i].sd << el ;
	}
	return 0;
}
