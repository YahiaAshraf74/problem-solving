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
const int N = 5e3 + 74, OO = 0x3f3f3f3f;

int n, m, T;
vector<pair<int, int>> adj[N];
int mem[N][N];
int dp(int node, int depth) {
    if (!depth || node == n && depth != 1)
        return OO;
    if (node == n)
        return 0;
    int &ret = mem[node][depth];
    if (~ret)
        return ret;
    ret = OO;
    for (auto child: adj[node])
        ret = min(ret, dp(child.first, depth - 1) + child.second);
    return mem[node][depth] = ret;
}

void build(int node, int depth) {
    for (auto child: adj[node]) {
        if (dp(child.first, depth - 1) + child.second == mem[node][depth]) {
            cout << node << ' ';
            build(child.first, depth - 1);
            break;
        }
    }
}


class CJourney {
public:
    void solve(istream &cin, ostream &cout) {
        cin >> n >> m >> T;
        for (int i = 0; i < m; ++i) {
            int u, v, t;
            cin >> u >> v >> t;
            adj[u].push_back({v, t});
        }
        clr(mem, -1);
        for (int depth = m + 1; depth > 0; --depth) {
            if (dp(1, depth) <= T) {
                cout << depth << el;
                build(1, depth);
                cout << n << el;
                break;
            }
        }
    }
};