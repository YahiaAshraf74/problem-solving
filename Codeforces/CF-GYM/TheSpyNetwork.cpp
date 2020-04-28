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


vector<array<int, 3>> adj[N];
vector<int> ans;

class TheSpyNetwork {
public:
    void init() {
        for (int i = 0; i < N; i++)
            adj[i].clear();
        ans.clear();
    }

    int dfs(int u, int cur, int dep) {
        int mx = (dep - cur) * 2 >= dep ? 0 : (dep + 1) / 2 - (dep - cur);
        for (array<int, 3> v : adj[u]) {
            int x = dfs(v[0], cur + v[1], dep + 1);
            if (x > cur)
                ans.push_back(v[2]), --x;
            mx = max(mx, x);
        }
        return mx;
    }

    void solve(istream &cin, ostream &cout) {
        init();
        int n;
        cin >> n;
        for (int i = 1; i < n; i++) {
            int u, v;
            string s;
            cin >> u >> v >> s;
            adj[v].push_back({u, s[0] == 'a', i});
            if (s[0] == 'a')
                cin >> s;
        }
        dfs(1, 0, 0);
        cout << sz(ans) << el;
        for(int i : ans)
            cout << i << ' ';
    }
};