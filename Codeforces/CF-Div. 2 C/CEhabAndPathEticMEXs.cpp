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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;
#define el  '\n'
#define ll long long
#define sz(a) (int)(a).size()
template<typename T> using heap = priority_queue<T, vector<T>, less<T>>;
using ordered_set =  tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
const long long N = 2e5 + 74, OO = 0x3f3f3f3f, MOD = (long long) 1e9 + 7;

int deg[N];
pair<int, int> ls[N];

class CEhabAndPathEticMEXs {
public:
    void solve(istream &cin, ostream &cout) {
        int n;
        cin >> n;
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            deg[u]++, deg[v]++;
            ls[i] = {u, v};
        }
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            if (deg[i] >= 3) {
                mx = i;
                break;
            }
        }
        if (mx == 0) {
            for (int i = 0; i < n - 1; i++)
                cout << i << el;
            memset(ls, 0, sizeof(ls));
            memset(deg, 0, sizeof(deg));
            return;
        }
        int cnt = 0, q = 3;
        for (int i = 0; i < n - 1; i++) {
            if ((ls[i].first == mx || ls[i].second == mx) && cnt < 3)
                cout << cnt++ << el;
            else
                cout << q++ << el;
        }
        memset(ls, 0, sizeof(ls));
        memset(deg, 0, sizeof(deg));
    }
};