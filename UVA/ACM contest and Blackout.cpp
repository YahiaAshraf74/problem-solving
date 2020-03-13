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
	freopen("input.txt", "r", stdin); // freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

vector<pair<pair<int, bool>, pair<int, int>> > edges(174);
int T, n, m, from, to, cost, mstCost1, mstCost2, mnMstCost2, par[174], sz[174];
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

int main() {
	YAHIA();
	cin >> T;
	while (T--) {
		cin >> n >> m;
		clr(sz,0) ;
		clr(par,0) ;
		disJoint d1(n);
		edges.clear();
		mstCost1 = 0;
		mnMstCost2  = INT_MAX;
		lp(i,m){
			cin >> from >> to >> cost;
			edges.pb(mp(mp(cost,0),mp(from,to)));
		}
		sort(all(edges));
		lp(i,m)
			if (d1.unionSet(edges[i].sd.ft, edges[i].sd.sd)) {
				mstCost1 += edges[i].ft.ft;
				edges[i].ft.sd = true;
			}
		lp(i,m-1){
			if (edges[i].ft.sd) {
				clr(sz,0) ;
				clr(par,0) ;
				mstCost2 = 0;
				disJoint d2(n);
				int mstFrom = edges[i].sd.ft, mstTo = edges[i].sd.sd, mstCost =
						edges[i].ft.ft, ed = 0;
				edges.erase(edges.begin() + i);
				sort(all(edges));
				lp(j,m)
					if (d2.unionSet(edges[j].sd.ft, edges[j].sd.sd)) {
						mstCost2 += edges[j].ft.ft;
						++ed ;
					}
				edges.pb(mp(mp(mstCost,1),mp(mstFrom,mstTo)));
				if (ed != n - 1)
					continue;
				mnMstCost2 = min(mnMstCost2, mstCost2);
			}
		}
		cout << mstCost1 << " " << mnMstCost2 << el;
	}
	return 0;
}
