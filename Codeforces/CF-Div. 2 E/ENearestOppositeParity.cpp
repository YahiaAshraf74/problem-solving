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

int n;
int a[N], d[N], ans[N];
vector<int> adj[N];

class ENearestOppositeParity {
public:
    void init() {

    }

    void bfs(const vector<int> &start, const vector<int> &end) {
        clr(d, OO);
        queue<int> q;
        for (auto v : start) {
            d[v] = 0;
            q.push(v);
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v : adj[u]) {
                if (d[v] == OO) {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
        for (auto v : end) {
            if (d[v] != OO) {
                ans[v] = d[v];
            }
        }
    }

    void solve(istream &cin, ostream &cout) {
        init();
        int n;
        cin >> n;
        vector<int> even, odd;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] & 1)
                odd.push_back(i);
            else
                even.push_back(i);
        }
        for (int i = 0; i < n; ++i) {
            if (0 <= i - a[i])
                adj[i - a[i]].push_back(i);
            if (i + a[i] < n)
                adj[i + a[i]].push_back(i);
        }
        clr(ans, -1);
        bfs(odd, even);
        bfs(even, odd);
        for (int i = 0; i < n; i++)
            cout << ans[i] << ' ';

    }
};