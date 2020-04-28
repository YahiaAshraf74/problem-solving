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

int a[N];
pair<int, int> tree[N * 4];

class MaximumSum {
public:
    void init() {

    }

    pair<int, int> max(pair<int, int> a, pair<int, int> b) {
        vector<int> v{a.first, a.second, b.first, b.second};
        sort(v.begin(), v.end(), greater<int>());
        return {v[0], v[1]};
    }

    void build(int n, int st, int ed) {
        if (st == ed) {
            tree[n].first = a[st];
            return;
        }
        int mid = (st + ed) >> 1;
        build(n * 2 + 1, st, mid);
        build(n * 2 + 2, mid + 1, ed);
        tree[n] = max(tree[n * 2 + 1], tree[n * 2 + 2]);
    }

    void update(int n, int st, int ed, int idx, int val) {
        if (st == ed && st == idx) {
            a[idx] = val;
            tree[n].first = a[idx];
        } else if (idx < st || idx > ed) {
            return;
        } else {
            int mid = (st + ed) >> 1;
            update(n * 2 + 1, st, mid, idx, val);
            update(n * 2 + 2, mid + 1, ed, idx, val);
            tree[n] = max(tree[n * 2 + 1], tree[n * 2 + 2]);
        }
    }

    pair<int, int> quary(int n, int st, int ed, int l, int r) {
        if (ed < l || st > r) {
            return {0, 0};
        } else if (st >= l && ed <= r) {
            return tree[n];
        } else {
            int mid = (st + ed) >> 1;
            return max(quary(n * 2 + 1, st, mid, l, r), quary(n * 2 + 2, mid + 1, ed, l, r));
        }
    }

    void solve(istream &cin, ostream &cout) {
        init();
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        build(0, 0, n - 1);
        int q;
        cin >> q;
        while (q--) {
            char type;
            cin >> type;
            if (type == 'U') {
                int idx, val;
                cin >> idx >> val;
                update(0, 0, n - 1, idx-1, val);
            } else {
                int l, r;
                cin >> l >> r;
                auto q = quary(0, 0, n - 1, l-1, r-1);
                cout << q.first + q.second << el;
            }
        }
    }
};