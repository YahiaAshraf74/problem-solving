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
#define el    '\n'
#define ll long long
#define clr(a, b)memset(a,b,sizeof(a))
#define all(v)((v).begin()),((v).end())
#define write(v) freopen(v,"w",stdout)
const int N = 1e5 + 74, OO = 0x3f3f3f3f;

pair<int, pair<int, int>> quary[N];
set<int> id[N];
int par[N];
int ans[N];

int find(int x) {
    if (x == par[x]) return x;
    else return par[x] = find(par[x]);
}

void helpJoin(int u, int v, int s) {
    for (auto it : id[v]) {
        if (id[u].find(it) != id[u].end()) {
            ans[it] = s;
            id[u].erase(id[u].find(it));
        } else {
            id[u].insert(it);
        }
    }
}

void join(int u, int v, int s) {
    u = find(u), v = find(v);
    if (u == v)
        return;
    if ((int) id[u].size() > (int) id[v].size()) {
        helpJoin(u, v, s);
        par[v] = par[u];
    } else {
        helpJoin(v, u, s);
        par[u] = par[v];
    }
}

class CConnectingGraph {
public:
    void solve(istream &cin, ostream &cout) {
        int T;
        cin >> T;
        while (T--) {
            int n, m;
            cin >> n >> m;
            for (int i = 1; i <= n; i++)
                id[i].clear(), par[i] = i;
            for (int i = 1; i <= m; i++) {
                int type, u, v;
                cin >> type >> u >> v;
                if (type == 2)
                    id[u].insert(i), id[v].insert(i);
                quary[i] = {type, {u, v}};
                ans[i] = -1;
            }
            for (int i = 1; i <= m; i++) {
                if (quary[i].first == 1) {
                    join(quary[i].second.first, quary[i].second.second, i);
                } else {
                    cout << ans[i] << el;
                }
            }
        }
    }
};