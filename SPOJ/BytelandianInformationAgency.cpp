#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <complex>
#include <string>
#include <bitset>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <assert.h>
using namespace std;
#define el  '\n'
#define ll long long
#define clr(a,b)memset(a,b,sizeof(a))
#define sz(a) (int)(a).size()
const long long N = (int)5e3 + 3, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

vector<int> adj[N];
int vis[N] , vid = 1;
class BytelandianInformationAgency {
public:
    void init(int n){
        for(int i  =0;i<=n;i++)
            adj[i].clear();
        vid++;
    }

    void dfs(int u,int t){
        vis[u] = vid;
        for(int v : adj[u]){
            if(vis[v] != vid && v != t){
                dfs(v,t);
            }
        }
    }

	void solve(istream& cin, ostream& cout) {
        int n,m;
        while(cin >> n >> m){
            init(n);
            for(int i = 0;i<m;i++){
                int u ,v;
                cin >> u >> v;
                adj[u].push_back(v);
            }
            vector<int> criticalComputers;
            for(int i = 1;i<=n;i++){
                dfs(1,i);
                if(count(vis+1,vis+n+1,vid) != n-1)
                    criticalComputers.push_back(i);
                vid++;
            }
            cout << sz(criticalComputers) << el;
            for(int i : criticalComputers)
                cout << i << ' '; 
            cout << el;
        }
	}
};