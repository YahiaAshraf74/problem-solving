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
const long long N = 1e5 + 2, OO = 0x3f3f3f3f, MOD = (long long) 1e9 + 7;

ll tree[N * 4], lazy[N * 4];

void init(int n) {
    memset(tree, 0, sizeof(tree[0]) * n * 4 + 1);
    memset(lazy, 0, sizeof(lazy[0]) * n * 4 + 1);
}

void updateRange(int n, int st, int ed, int l, int r) {
    if (st > ed)
        return;
    if (lazy[n] != 0) {
        tree[n] += (ed - st + 1) * lazy[n];
        if (st != ed)
            lazy[n * 2 + 1] += lazy[n], lazy[n * 2 + 2] += lazy[n];
        lazy[n] = 0;
    }
    if (st > r || ed < l)
        return;
    else if (st >= l && ed <= r) {
        tree[n] += (ed - st + 1);
        if (st != ed)
            lazy[n * 2 + 1]++, lazy[n * 2 + 2]++;
    } else {
        int mid = (st + ed) / 2;
        updateRange(n * 2 + 1, st, mid, l, r);
        updateRange(n * 2 + 2, mid + 1, ed, l, r);
        tree[n] = tree[n * 2 + 1] + tree[n * 2 + 2];
    }
}

ll queryRange(int n, int st, int ed, int l, int r) {
    if (lazy[n] != 0) {
        tree[n] += (ed - st + 1) * lazy[n];
        if (st != ed)
            lazy[n * 2 + 1] += lazy[n], lazy[n * 2 + 2] += lazy[n];
        lazy[n] = 0;
    }
    if (st > r || ed < l)
        return 0;
    else if (st >= l && ed <= r)
        return tree[n];
    int mid = (st + ed) / 2;
    return queryRange(n * 2 + 1, st, mid, l, r) + queryRange(n * 2 + 2, mid + 1, ed, l, r);
}

class HaltTheWar {
public:
    void solve(istream &cin, ostream &cout) {
        int T, testCases = 1;
        string type;
        cin >> T;
        while (T--) {
            int n, q;
            cin >> n >> q;
            init(n);
            cout << "Scenario #" << testCases++ << ":\n";
            while (q--) {
                int l, r;
                cin >> type >> l >> r;
                if (type[0] == 'a') {
                    cout << queryRange(0, 0, n - 1, l - 1, r - 1) << el;
                } else {
                    updateRange(0, 0, n - 1, l - 1, r - 1);
                    cout << "OK\n";
                }
            }
        }
    }
};