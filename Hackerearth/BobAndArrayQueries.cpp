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
#define popcount(x) __builtin_popcountll(x)
const long long N = 5e5 + 74, OO = 0x3f3f3f3f, MOD = (long long) 1e9 + 7;

int a[N];
int tree[N * 4];

void update(int n, int st, int ed, int idx, int type) {
    if (st == ed) {
        (type == 1) ? a[idx]++, tree[n]++ : (a[idx] > 0) ? a[idx]--, tree[n]-- : 0;
        return;
    }
    int mid = (st + ed) / 2;
    if (idx >= st && idx <= mid) {
        update(n * 2 + 1, st, mid, idx, type);
    } else {
        update(n * 2 + 2, mid + 1, ed, idx, type);
    }
    tree[n] = tree[n * 2 + 1] + tree[n * 2 + 2];
}

int quary(int n, int st, int ed, int l, int r) {
    if (l > ed || r < st)
        return 0LL;
    else if (l <= st && r >= ed)
        return tree[n];
    else {
        int mid = (st + ed) / 2;
        return quary(n * 2 + 1, st, mid, l, r) + quary(n * 2 + 2, mid + 1, ed, l, r);
    }
}

class BobAndArrayQueries {
public:
    void solve(istream &cin, ostream &cout) {
        int n, q;
        cin >> n >> q;
        while (q--) {
            int type;
            cin >> type;
            if (type <= 2) {
                int idx;
                cin >> idx;
                update(0, 0, n - 1, idx - 1, type);
            } else {
                int l, r;
                cin >> l >> r;
                cout << quary(0, 0, n - 1, l - 1, r - 1) << el;
            }
        }
    }
};