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

int n , m , cost , T ;
string from , to ;
vector <pair <int , pair <string ,string >> > edges ;
set <string> seet ;
map <string , string> par ;
map <string , int > sz ;

struct disJoint {
	int connComp ,sizeOfDisJoint;
	disJoint(int size) {
		connComp = sizeOfDisJoint = size;
		for (string node : seet){
			par[node]  = node;
			sz[node] = 1 ;
		}
	}
	string find(string node) {
		string root = node;
		while (root != par[root])
			root = par[root];
		while (node != root) {
			string next = par[node];
			par[node] = root;
			node = next;
		}
		return root;
	}
	bool unionSet(string node1, string node2) {
		string root1 = find(node1), root2 = find(node2);
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
		return 1 ;
	}
	int numOfConnComp() {
		return connComp;
	}
	bool connected(string node1, string node2) {
		return find(node1) == find(node2);
	}
	int componentSize(string node) {
	    return sz[find(node)];
	}
	int size() {
	    return sizeOfDisJoint;
	}

};
int main() {
	YAHIA();
	cin >> T ;
	lpv(tc,1,T){
		seet.clear() ;
		edges.clear();
		cin >> n >> m ;
		lp(i,m){
			cin >> from >> to >> cost ;
			seet.insert(from) , seet.insert(to) ;
			edges.pb(mp(cost,mp(from,to))) ;
		}
		disJoint d1(n) ;
		sort(all(edges)) ;
		int mstCost = 0 ;
		lp(i,m){
			if (d1.unionSet(edges[i].sd.ft , edges[i].sd.sd)){
				mstCost += edges[i].ft  ;
			}
		}
		if (tc !=1) cout << el ;
		cout << mstCost << el ;

	}
	return 0;
}
