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
const long long N = (int) 1e5 + 74, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

int n, m, w;
int a[N];
pair<int, int> tree[N * 4];
int lazy[N * 4];

class CPresent {
public:
    void init() {
        clr(tree, 0);
        clr(lazy, 0);
    }

    void build(int n, int st, int ed) {
        if (st == ed) {
            tree[n] = {a[st], st};
            return;
        }
        int mid = (st + ed) >> 1;
        build(n * 2 + 1, st, mid);
        build(n * 2 + 2, mid + 1, ed);
        tree[n] = (tree[n * 2 + 1].first <= tree[n * 2 + 2].first) ? tree[n * 2 + 1] : tree[n * 2 + 2];
    }

    pair<int, int> getMin(int n, int st, int ed, int l, int r) {
        if (lazy[n] != 0) {
            tree[n].first += lazy[n];
            if (st != ed)
                lazy[n * 2 + 1] += lazy[n], lazy[n * 2 + 2] += lazy[n];
            lazy[n] = 0;
        }
        if (st > r || ed < l)
            return {OO, OO};
        else if (st >= l && ed <= r)
            return tree[n];
        else {
            int mid = (st + ed) >> 1;
            auto q1 = getMin(n * 2 + 1, st, mid, l, r);
            auto q2 = getMin(n * 2 + 2, mid + 1, ed, l, r);
            return (q1.first <= q2.first) ? q1 : q2;
        }
    }

    void updateRange(int n, int st, int ed, int l, int r) {
        if (lazy[n] != 0) {
            tree[n].first += lazy[n];
            if (st != ed)
                lazy[n * 2 + 1] += lazy[n], lazy[n * 2 + 2] += lazy[n];
            lazy[n] = 0;
        }
        if (st > r || ed < l)
            return;
        else if (st >= l && ed <= r) {
            tree[n].first++;
            if (st != ed)
                lazy[n * 2 + 1]++, lazy[n * 2 + 2]++;
        } else {
            int mid = (st + ed) >> 1;
            updateRange(n * 2 + 1, st, mid, l, r);
            updateRange(n * 2 + 2, mid + 1, ed, l, r);
            tree[n] = (tree[n * 2 + 1].first <= tree[n * 2 + 2].first) ? tree[n * 2 + 1] : tree[n * 2 + 2];
        }
    }

    void solve(istream &cin, ostream &cout) {
        init();
        cin >> n >> m >> w;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        build(0, 0, n - 1);
        for (int i = 0; i < m; i++) {
            auto mn = getMin(0, 0, n - 1, 0, n - 1);
            auto mn2 = getMin(0, 0, n - 1, mn.second, min(mn.second + w - 1, n - 1));
            if (mn.second + w - 1 < n) {
                updateRange(0, 0, n - 1, mn.second, mn.second + w - 1);
            } else {
                updateRange(0, 0, n - 1, n - w, n - 1);
            }
        }
        cout << getMin(0, 0, n - 1, 0, n - 1).first << el;
    }
};