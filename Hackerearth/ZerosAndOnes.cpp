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
const long long N = 1e6 + 1, OO = 0x3f3f3f3f, MOD = (long long) 1e9 + 7;

int tree[N * 4];

void build(int node, int st, int en) {
    if (st == en) {
        tree[node] = 1;
        return;
    }
    int mid = (st + en) / 2;
    build(2 * node, st, mid);
    build(2 * node + 1, mid + 1, en);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void update(int node, int st, int ed, int index) {
    if (st == ed) {
        tree[node] = 0;
        return;
    }
    int mid = (st + ed) / 2;
    if (index >= st && index <= mid) {
        update(2 * node, st, mid, index);
    } else {
        update(2 * node + 1, mid + 1, ed, index);
    }
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int node, int st, int en, int k, int n) {
    if (st < 1 || en > n || tree[node] < k)
        return -1;
    if (st == en && k == 1)
        return st;
    int mid = (st + en) / 2;
    int leftNode = tree[2 * node];
    if (k <= leftNode) {
        return query(2 * node, st, mid, k, n);
    } else {
        return query(2 * node + 1, mid + 1, en, k - leftNode, n);
    }
}

class ZerosAndOnes {
public:
    void solve(istream &cin, ostream &cout) {
        int n;
        cin >> n;
        build(1, 1, n);
        int q;
        cin >> q;
        while (q--) {
            int type;
            cin >> type;
            if (type) {
                int k;
                cin >> k;
                cout << query(1, 1, n, k, n) << el;
            } else {
                int idx;
                cin >> idx;
                update(1, 1, n, idx);
            }
        }
    }
};