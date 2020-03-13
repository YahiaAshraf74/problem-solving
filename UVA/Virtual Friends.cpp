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

int T, n;
string f1 , f2 ;
map <string , string > par ;
map <string , int > sz ;
set <string> st ;
vector<pair <string ,string>> vec ;
struct disJoint {
	int connComp, sizeOfDisJoint;
	disJoint(int size) {
		connComp = sizeOfDisJoint = size;
		for(auto name : st){
			par[name] =name ;
			sz[name] = 1 ;
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
		return 1;
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
	cin >> T;
	lpv(tc,1,T){
		vec.clear();
		st.clear() ;
		par.clear() ;
		sz.clear() ;
		cin >> n ;
		lp(i,n){
			cin >> f1  >> f2 ;
			st.insert(f1) ;
			st.insert(f2) ;
			vec.pb(mp(f1,f2)) ;
		}
		disJoint d1(sz(st));
		lp(i,sz(vec)){
			d1.unionSet(vec[i].ft,vec[i].sd) ;
			cout << d1.componentSize(vec[i].ft) <<el;
		}
	}
	return 0;
}
