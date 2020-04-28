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
const long long N = (int) 5e4 + 2, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

int n, k;
ll dp[N][502];
ll cnt;
vector<int> adj[N];

void dfs(int u, int p) {
    dp[u][0] = 1;
    for (auto v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            for (int i = 0; i < k; i++)
                cnt += dp[u][i] * dp[v][k - i - 1];
            for (int i = 1; i <= k; i++)
                dp[u][i] += dp[v][i - 1];
        }
    }
}

class DDistanceInTree {
public:
    void init() {
        for (int i = 1; i < N; i++)
            adj[i].clear();
        cnt = 0;
        clr(dp, 0);
    }

    void solve(istream &cin, ostream &cout) {
        init();
        cin >> n >> k;
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int u = 1; u <= n; u++) {
            dp[u][1] = sz(adj[u]);
        }

    }
};