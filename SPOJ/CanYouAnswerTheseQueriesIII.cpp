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
const long long N = (int) 5e4 + 2, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

struct Node {
    int sum, pre, suf, mxSum;

    Node() {}

    Node(int val) {
        sum = mxSum = pre = suf = val;
    }

    Node(int s, int p, int sf, int mx) {
        sum = s;
        pre = p;
        suf = sf;
        mxSum = mx;
    }
};

int a[N];
Node tree[N * 4];

class CanYouAnswerTheseQueriesIII {
public:
    void init() {

    }

    Node merge(Node left, Node right) {
        Node par;
        par.sum = left.sum + right.sum;
        par.pre = max(left.pre, left.sum + right.pre);
        par.suf = max(right.suf, right.sum + left.suf);
        par.mxSum = max(max(left.mxSum, right.mxSum), left.suf + right.pre);
        return par;
    }

    void build(int n, int st, int ed) {
        if (st == ed) {
            tree[n] = Node(a[st]);
            return;
        }
        int mid = (st + ed) / 2;
        build(n * 2, st, mid);
        build(n * 2 + 1, mid + 1, ed);
        tree[n] = merge(tree[n * 2], tree[n * 2 + 1]);
    }

    void update(int n, int st, int ed, int idx, int val) {
        if (st == ed) {
            a[st] = val;
            tree[n] = Node(a[st]);
            return;
        }
        int mid = (st + ed) / 2;
        if (idx <= mid) {
            update(n * 2, st, mid, idx, val);
        } else {
            update(n * 2 + 1, mid + 1, ed, idx, val);
        }
        tree[n] = merge(tree[n * 2], tree[n * 2 + 1]);
    }

    Node quary(int n, int st, int ed, int l, int r) {
        if (st > r || ed < l)
            return Node(0, -OO, -OO, -OO);
        else if (st >= l && ed <= r)
            return tree[n];
        else {
            int mid = (st + ed) / 2;
            return merge(quary(n * 2, st, mid, l, r), quary(n * 2 + 1, mid + 1, ed, l, r));
        }
    }

    void solve(istream &cin, ostream &cout) {
        init();
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        build(1, 1, n);
        int q;
        cin >> q;
        while (q--) {
            int type;
            cin >> type;
            if (type == 0) {
                int idx, val;
                cin >> idx >> val;
                update(1, 1, n, idx, val);
            } else {
                int l, r;
                cin >> l >> r;
                cout << quary(1, 1, n, l, r).mxSum << el;
            }
        }
    }
};