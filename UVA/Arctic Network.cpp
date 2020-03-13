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
vector <pair <int ,int > > outputs ,ans ;
int T, s, p, x , y, done, par[574], sz[574];
double mx ;
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
    return sqrt((p.ft - p1.ft)*(p.ft - p1.ft)+(p.sd-p1.sd)*(p.sd-p1.sd));
}
int main() {
	YAHIA();
	cin >> T;
	while(T--){
		mx = 0 ,done = 0;
		clr(sz,0) ;
		clr(par,0);
		outputs.clear() ;
		edges.clear() ;
		cin >> s >> p ;
		disJoint d1(p) ;
		lp(i,p){
			cin >> x >> y ;
			outputs.pb(mp(x,y));
		}
		lpv(i,1,p)
			lpv(j,i+1,p)
				edges.pb(mp(getDistance(outputs[i-1],outputs[j-1]) ,mp(i,j)));
		sort(all(edges)) ;

		for (auto edge : edges){
			if (d1.unionSet(edge.sd.ft , edge.sd.sd)){
				++done;
				mx = max(mx,edge.ft) ;
				if (done == p-s)break ;
			}
		}
		cout << fixed << setprecision(2) << mx << el ;
	}
	return 0;
}
