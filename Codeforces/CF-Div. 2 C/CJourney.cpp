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
#include <assert.h>

using namespace std;
#define el    '\n'
#define ll long long
#define clr(a, b)memset(a,b,sizeof(a))
#define all(v)((v).begin()),((v).end())
#define write(v) freopen(v,"w",stdout)
const int N = 1e5 + 74, OO = 0x3f3f3f3f;

vector<int> adj[N];
bool vis[N];
long double ret = 0.0;

void dfs(int u = 1, int d = 0, long double prop = 1.0) {
    vis[u] = true;
    int sz = (int)adj[u].size() - (u != 1);
    if (sz == 0)
        ret += (long double) prop * d;
    else {
        for (int v : adj[u]) {
            if (!vis[v])
                dfs(v, d + 1, prop * (1.0 / sz));
        }
    }
}

class CJourney {
public:
    void solve(istream &cin, ostream &cout) {
        int n;
        cin >> n;
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs();
        cout << fixed << setprecision(12) << ret << el;
        ret = 0.0;
        for (int i = 1; i <= n; i++)
            adj[i].clear();
        clr(vis, false);
    }
};