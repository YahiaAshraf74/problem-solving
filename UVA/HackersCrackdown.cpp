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

vector<int> adj[20];
bool vis[20];
int cnt = 0;

class HackersCrackdown {
public:
    void init() {
        for (int i = 0; i < 20; i++)
            adj[i].clear();
        clr(vis, false);
    }

    void dfs(int u) {
        vis[u] = true;
        ++cnt;
        for (auto v : adj[u]) {
            if (!vis[v]) {
                dfs(v);
            }
        }
    }

    void solve(istream &cin, ostream &cout) {
        int n, testCases = 1;
        while (cin >> n) {
            init();
            if (!n)
                break;
            for (int i = 0; i < n; i++) {
                int m;
                cin >> m;
                for (int j = 0; j < m; j++) {
                    int x;
                    cin >> x;
                    adj[i].push_back(x);
                }
            }
            cout << "Case " << testCases++ << ": ";
            int mx = 0;
            for (int i = 0; i < n; i++) {
                if (!vis[i]) {
                    cnt = 0;
                    dfs(i);
                    mx = max(mx, cnt);
                }
            }
            cout << mx << el;
        }
    }
};