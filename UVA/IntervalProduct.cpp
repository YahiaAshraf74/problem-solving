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
const long long N = 1e5 + 74, OO = 0x3f3f3f3f, MOD = (long long) 1e9 + 7;

int a[N];
pair<int, bool> tree[N * 4];

class IntervalProduct {
public:
    void init() {
        clr(tree, 0);
    }

    void build(int n, int st, int ed) {
        if (st == ed) {
            tree[n] = {a[st] < 0, (a[st] == 0) ? true : false};
            return;
        }
        int mid = (st + ed) / 2;
        build(n * 2 + 1, st, mid);
        build(n * 2 + 2, mid + 1, ed);
        tree[n] = {tree[n * 2 + 1].first + tree[n * 2 + 2].first, tree[n * 2 + 1].second || tree[n * 2 + 2].second};
    }

    void update(int n, int st, int ed, int idx, int val) {
        if (st == ed) {
            a[idx] = val;
            tree[n] = {a[idx] < 0, (a[idx] == 0) ? true : false};
            return;
        }
        int mid = (st + ed) / 2;
        if (idx >= st && idx <= mid) {
            update(n * 2 + 1, st, mid, idx, val);
        } else {
            update(n * 2 + 2, mid + 1, ed, idx, val);
        }
        tree[n] = {tree[n * 2 + 1].first + tree[n * 2 + 2].first, tree[n * 2 + 1].second || tree[n * 2 + 2].second};
    }

    pair<int, bool> quary(int n, int st, int ed, int i, int j) {
        if (i > ed || j < st)
            return {0, false};
        else if (st >= i && ed <= j)
            return tree[n];
        else {
            int mid = (st + ed) / 2;
            auto q1 = quary(n * 2 + 1, st, mid, i, j);
            auto q2 = quary(n * 2 + 2, mid + 1, ed, i, j);
            return {q1.first + q2.first, q1.second || q2.second};
        }
    }

    void solve(istream &cin, ostream &cout) {
        int n, q;
        while (cin >> n >> q) {
            init();
            for (int i = 0; i < n; i++) {
                cin >> a[i];
            }
            build(0, 0, n - 1);
            string ans = "";
            while (q--) {
                char type;
                cin >> type;
                if (type == 'C') {
                    int idx, val;
                    cin >> idx >> val;
                    update(0, 0, n - 1, idx - 1, val);
                } else {
                    int i, j;
                    cin >> i >> j;
                    auto q = quary(0, 0, n - 1, i - 1, j - 1);
                    (q.second == true) ? ans.push_back('0') : (q.first & 1) ? ans.push_back('-') : ans.push_back('+');
                }
            }
            cout << ans << el;
        }
    }
};