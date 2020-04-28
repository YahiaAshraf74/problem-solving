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
#define el  '\n'
#define ll long long
#define clr(a, b)memset(a,b,sizeof(a))
#define sz(a) (int)(a).size()
const long long N = (int) 2e5 + 74, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

vector<int> adj[N];
bool vis[N];
int dp[N];
class GLongestPath {
public:
    void init() {
        for (int i = 0; i < N; i++)
            adj[i].clear();
        clr(vis, false);
        clr(dp, 0);
    }

    void dfs(int u) {
        vis[u] = true;
        for (int v : adj[u]) {
            if (!vis[v]) {
                dfs(v);
            }
            dp[u] = max(dp[u], dp[v] + 1);
        }
    }

    void solve(istream &cin, ostream &cout) {
        init();
        int n, m;
        cin >> n >> m;
        while (m--) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                dfs(i);
            }
        }
        cout << *max_element(dp,dp+n+1) << el;
    }
};