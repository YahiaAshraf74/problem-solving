#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include<stack>
#include <complex>
#include <string>
#include <bitset>
#include <stdio.h>
#include <string.h>
#include<fstream>
#include <iomanip> 
using namespace std;
#define el	'\n'
#define ll long long
#define clr(a,b)memset(a,b,sizeof(a))
#define all(v)((v).begin()),((v).end())
#define write(v) freopen(v,"w",stdout)
const int N = 1e5 + 74, OO = 0x3f3f3f3f;

vector<pair<int,int>> adj[N];
vector<ll> ans;
void dfs(int u ,ll sum = 0){
    for(int i =0;i<(int)adj[u].size();i++){
        ll v = adj[u][i].second , w = adj[u][i].first;
        dfs(v,sum + (w*2) - adj[u][0].first);
        }
    if(adj[u].empty())
        ans.push_back(sum);
}
class DFrozenRivers {
public:
	void solve(istream& cin, ostream& cout) {
        int T;
        cin >> T;
        while(T--){
            int n;
            cin >> n;
            for(int i=1;i<=n;i++)
                adj[i].clear();
            ans.clear();
            for (int u = 2; u <= n ; ++u) {
                int v , w;
                cin >> v >> w;
                adj[v].push_back({w,u});
            }
            for(int u = 1;u<=n;u++)
                sort(all(adj[u]));
            dfs(1);
            sort(all(ans));
            int q;
            cin >> q;
            while(q--){
                ll t;
                cin >> t;
                ll idx = upper_bound(all(ans),t) - ans.begin();
                cout << idx   << el;
            }
        }
	}
};