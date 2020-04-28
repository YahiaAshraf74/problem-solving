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

int timeSoFar;
vector<int> p, d;
vector<int> tin, tout;
vector<vector<int>> adj;

class ETreeQueries {
public:
    void init() {
    }

    void dfs(int v, int par = -1, int dep = 0) {
        p[v] = par;
        d[v] = dep;
        tin[v] = timeSoFar++;
        for (auto to : adj[v]) {
            if (to == par)
                continue;
            dfs(to, v, dep + 1);
        }
        tout[v] = timeSoFar++;
    }

    bool isAnc(int v, int u) {
        return tin[v] <= tin[u] && tout[u] <= tout[v];
    }

    void solve(istream &cin, ostream &cout) {
        init();
        int n, m;
        cin >> n >> m;
        p = d = vector<int>(n);
        tin = tout = vector<int>(n);
        adj = vector<vector<int>>(n);
        for (int i = 0; i < n - 1; ++i) {
            int x, y;
            cin >> x >> y;
            --x, --y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs(0);
        for (int i = 0; i < m; ++i) {
            int k;
            cin >> k;
            vector<int> v(k);
            for (auto &it : v) {
                cin >> it;
                --it;
            }
            int u = v[0];
            for (auto it : v) 
                if (d[u] < d[it])
                    u = it;
            for (auto &it : v) {
                if (it == u || p[it] == -1) 
                    continue;
                it = p[it];
            }
            bool can = true;
            for (auto it : v)
                can &= isAnc(it, u);
            if (can)
                cout << "YES" << el;
            else
                cout << "NO" << el;
        }

    }
};