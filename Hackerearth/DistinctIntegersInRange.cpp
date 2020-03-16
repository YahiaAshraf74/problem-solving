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
const long long N = 1e5 + 5, OO = 0x3f3f3f3f, MOD = (long long) 1e9 + 7;

int a[N], b[N];
bitset<5002> tree[4 * N][2];

void build(int n, int st, int ed) {
    if (st == ed) {
        tree[n][0].set(a[st]);
        tree[n][1].set(b[st]);
        return;
    }
    int mid = (st + ed) / 2;
    build(2 * n + 1, st, mid);
    build(2 * n + 2, mid + 1, ed);
    tree[n][0] = tree[2 * n + 1][0] | tree[2 * n + 2][0];
    tree[n][1] = tree[2 * n + 1][1] | tree[2 * n + 2][1];
}

bitset<5002> query(int n, int st, int ed, int l, int r, int t) {
    if (st > ed || st > r || ed < l)
        return 0;
    if (st >= l && ed <= r)
        return tree[n][t];
    int mid = (st + ed) / 2;
    return query(2 * n + 1, st, mid, l, r, t) | query(2 * n + 2, mid + 1, ed, l, r, t);
}

class DistinctIntegersInRange {
public:
    void solve(istream &cin, ostream &cout) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        build(0, 0, n - 1);
        int q;
        cin >> q;
        while (q--) {
            int l, r, l2, r2;
            cin >> l >> r >> l2 >> r2;
            cout << (query(0, 0, n-1, l-1, r-1, 0) | query(0, 0, n-1, l2-1, r2-1, 1)).count() << el;
        }
    }
};

/* TLE
        int a[N], b[N];
        set<int> idx[5001], idx2[5001];
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            idx[a[i]].insert(i);
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            idx2[b[i]].insert(i);
        }
        int q;
        cin >> q;
        while (q--) {
            int l, r, l2, r2;
            cin >> l >> r >> l2 >> r2;
            --l, --r, --l2, --r2;
            int res = 0;
            for (int i = 1; i <= 5000; i++) {
                auto it = idx[i].lower_bound(l);
                if (*it <= r && it != idx[i].end()) {
                    ++res;
                } else {
                    it = idx2[i].lower_bound(l2);
                    if (*it <= r2 && it != idx2[i].end())
                        ++res;
                }
            }
            cout << res << el;
        }*/