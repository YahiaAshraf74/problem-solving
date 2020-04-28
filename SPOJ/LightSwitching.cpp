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
const long long N = (int) 1e5 + 2, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

int tree[N * 4], lazy[N * 4];

class LightSwitching {
public:
    void init() {
        memset(tree, 0, sizeof(tree));
        memset(lazy, 0, sizeof(lazy));
    }

    void updateRange(int n, int st, int ed, int l, int r) {
        if (lazy[n] != 0) {
            tree[n] = (ed - st + 1) - tree[n];
            if (st != ed)
                lazy[n * 2 + 1] ^= 1, lazy[n * 2 + 2] ^= 1;
            lazy[n] = 0;
        }
        if (ed < l || st > r)
            return;
        else if (st >= l && ed <= r) {
            tree[n] = (ed - st + 1) - tree[n];
            if (st != ed)
                lazy[n * 2 + 1] ^= 1, lazy[n * 2 + 2] ^= 1;
        } else {
            int mid = (st + ed) >> 1;
            updateRange(n * 2 + 1, st, mid, l, r);
            updateRange(n * 2 + 2, mid + 1, ed, l, r);
            tree[n] = tree[n * 2 + 1] + tree[n * 2 + 2];
        }
    }


    int quaryRange(int n, int st, int ed, int l, int r) {
        if (lazy[n] != 0) {
            tree[n] = (ed - st + 1) - tree[n];
            if (st != ed)
                lazy[n * 2 + 1] ^= 1, lazy[n * 2 + 2] ^= 1;
            lazy[n] = 0;
        }
        if (ed < l || st > r)
            return 0;
        else if (st >= l && ed <= r) {
            return tree[n];
        } else {
            int mid = (st + ed) >> 1;
            return quaryRange(n * 2 + 1, st, mid, l, r) + quaryRange(n * 2 + 2, mid + 1, ed, l, r);
        }
    }

    void solve(istream &cin, ostream &cout) {
        init();
        int n, q;
        cin >> n >> q;
        while (q--) {
            int type, l, r;
            cin >> type >> l >> r;
            if (type == 0) {
                updateRange(0, 0, n - 1, l - 1, r - 1);
            } else {
                cout << quaryRange(0, 0, n - 1, l - 1, r - 1)   << el;
            }
        }
    }
};