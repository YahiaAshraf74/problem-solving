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
#define clr(a, b)memset(a,b,sizeof(a))
#define sz(a) (int)(a).size()
const long long N = (int) 2e3 + 5, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

int dist[N][N];
vector<pair<int, ll>> adj[N];
int par[N];
bool can = true;

class DDesignTutorialInverseTheProblem {
public:
    void init() {
        for (int i = 0; i < N; i++)
            adj[i].clear();
        iota(par, par + N - 1, 0);
        can = true;
    }

    int find(int u) {
        if (par[u] == u)
            return u;
        else
            return par[u] = find(par[u]);
    }

    bool join(int u, int v) {
        u = find(u), v = find(v);
        if (u == v)
            return false;
        par[v] = u;
        return true;
    }

    void dfs(int u, int p, int s, int d) {
        if (dist[u][s] != d)
            can = false;
        for (auto v : adj[u]) {
            if (v.first != p) {
                dfs(v.first, u, s, d + v.second);
            }
        }
    }

    void solve(istream &cin, ostream &cout) {
        init();
        int n;
        cin >> n;
        vector<array<int, 3>> edges;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> dist[i][j];
                if ((i == j && dist[i][j] != 0) || (i != j && dist[i][j] == 0))
                    can = false;
                else if (i < j)
                    edges.push_back({dist[i][j], i, j});
            }
        }
        sort(edges.begin(), edges.end());
        for (auto edge : edges) {
            if (join(edge[1], edge[2])) {
                adj[edge[1]].push_back({edge[2], dist[edge[1]][edge[2]]});
                adj[edge[2]].push_back({edge[1], dist[edge[1]][edge[2]]});
            }
        }
        for (int i = 0; i < n; i++) {
            dfs(i, -1, i, 0);
        }
        if (can) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
};