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


vector<tuple<int, int, ll>> ans;
ll debt[N];
stack<int> in, out;
class DDecreasingDebts {
public:
    void solve(istream &cin, ostream &cout) {
        int n, m;
        cin >> n >> m;
        while (m--) {
            ll u, v, c;
            cin >> u >> v >> c;
            debt[u] -= c, debt[v] += c;
        }
        for (int i = 1; i <= n; i++) {
            if (debt[i] > 0)
                in.push(i);
            else if (debt[i] < 0)
                out.push(i);
        }
        while (!in.empty() && !out.empty()) {
            int u = in.top(), v = out.top();
            in.pop(), out.pop();
            ll c = min(debt[u], -debt[v]);
            debt[u] -= c ;
            debt[v] += c ;
            ans.push_back({v, u, c});
            if (debt[u])
                in.push(u);
            if (debt[v])
                out.push(v);
        }
        cout << ans.size() << el;
        for (auto i : ans) {
            cout << get<0>(i)<< ' ' << get<1>(i) << ' ' << get<2>(i) << el;
        }
    }
};