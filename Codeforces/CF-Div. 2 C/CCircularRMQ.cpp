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

int a[N];
ll tree[N * 4], lazy[N * 4];

class CCircularRMQ {
public:
    void init(int n) {
        memset(tree, OO, sizeof(tree[0]) * 4 * n + 1);
    }

    void build(int n, int st, int ed) {
        if (st == ed) {
            tree[n] = a[st];
            return;
        }
        int mid = (st + ed) >> 1;
        build(n * 2 + 1, st, mid);
        build(n * 2 + 2, mid + 1, ed);
        tree[n] = min(tree[n * 2 + 1], tree[n * 2 + 2]);
    }

    void propagation(int n, int st, int ed) {
        tree[n] += lazy[n];
        if (st != ed)
            lazy[n * 2 + 1] += lazy[n], lazy[n * 2 + 2] += lazy[n];
        lazy[n] = 0;
    }

    void updateRange(int n, int st, int ed, int l, int r, int val) {
        if (lazy[n] != 0) {
            propagation(n, st, ed);
        }
        if (ed < l || st > r)
            return;
        else if (st >= l && ed <= r) {
            lazy[n] = val;
            propagation(n, st, ed);
        } else {
            int mid = (st + ed) >> 1;
            updateRange(n * 2 + 1, st, mid, l, r, val);
            updateRange(n * 2 + 2, mid + 1, ed, l, r, val);
            tree[n] = min(tree[n * 2 + 1], tree[n * 2 + 2]);
        }
    }

    ll quaryRange(int n, int st, int ed, int l, int r) {
        if (lazy[n] != 0) {
            propagation(n, st, ed);
        }
        if (ed < l || st > r)
            return OO;
        else if (st >= l && ed <= r) {
            return tree[n];
        } else {
            int mid = (st + ed) >> 1;
            return min(quaryRange(n * 2 + 1, st, mid, l, r), quaryRange(n * 2 + 2, mid + 1, ed, l, r));
        }
    }

    void updateCircular(int n, int st, int ed, int l, int r, int val) {
        if (l > r) {
            updateRange(0, 0, n - 1, l, n - 1, val);
            updateRange(0, 0, n - 1, 0, r, val);
        } else {
            updateRange(0, 0, n - 1, l, r, val);
        }
    }

    ll quaryCircular(int n, int st, int ed, int l, int r) {
        if (l > r) {
            return min(quaryRange(0, 0, n - 1, l, n - 1), quaryRange(0, 0, n - 1, 0, r));
        } else {
            return quaryRange(0, 0, n - 1, l, r);
        }
    }

    void solve(istream &cin, ostream &cout) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        init(n);
        build(0, 0, n - 1);
        int q;
        cin >> q;
        cin.ignore();
        while (q--) {
            string s;
            stringstream strStream;
            getline(cin, s);
            strStream << s;
            int l, r, val = OO;
            strStream >> l >> r >> val;
            if (val != OO) {
                updateCircular(n, 0, n - 1, l, r, val);
            } else {
                cout << quaryCircular(n, 0, n - 1, l, r) << el;
            }
        }
    }
};