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
const long long N = 1024002, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

string s;
int tree[N * 4][2];
array<char,N*4> lazy;

class AhoyPirates {
public:
    void init(int n) {
        clr(tree,0);
        lazy.fill('0');
        s.clear();
    }

    void build(int n, int st, int ed) {
        if (st == ed) {
            bool isOne = (s[st] == '1');
            tree[n][isOne] = 1;
            return;
        }
        int mid = (st + ed) >> 1;
        build(n * 2 + 1, st, mid);
        build(n * 2 + 2, mid + 1, ed);
        tree[n][0] = tree[n * 2 + 1][0] + tree[n * 2 + 2][0];
        tree[n][1] = tree[n * 2 + 1][1] + tree[n * 2 + 2][1];
    }

    void propagation(int n, int st, int ed) {
        if (lazy[n] == 'I') {
            swap(tree[n][0], tree[n][1]);
            for (int i = 1; i <= 2 && st != ed; i++) {
                if (lazy[n * 2 + i] == 'E')
                    lazy[n * 2 + i] = 'F';
                else if (lazy[n * 2 + i] == 'F')
                    lazy[n * 2 + i] = 'E';
                else if (lazy[n * 2 + i] == 'I')
                    lazy[n * 2 + i] = '0';
                else
                    lazy[n * 2 + i] = 'I';
            }
        } else {
            if (lazy[n] == 'F') {
                tree[n][1] += tree[n][0];
                tree[n][0] = 0;
            } else if (lazy[n] == 'E') {
                tree[n][0] += tree[n][1];
                tree[n][1] = 0;
            }
            if (st != ed)
                lazy[n * 2 + 1] = lazy[n * 2 + 2] = lazy[n];
        }
        lazy[n] = '0';
    }

    void updateRange(int n, int st, int ed, int l, int r, char type) {
        if (lazy[n] != '0')
            propagation(n, st, ed);
        if (st > r || ed < l)
            return;
        else if (st >= l && ed <= r) {
            lazy[n] = type;
            propagation(n, st, ed);
        } else {
            int mid = (st + ed) >> 1;
            updateRange(n * 2 + 1, st, mid, l, r, type);
            updateRange(n * 2 + 2, mid + 1, ed, l, r, type);
            tree[n][0] = tree[n * 2 + 1][0] + tree[n * 2 + 2][0];
            tree[n][1] = tree[n * 2 + 1][1] + tree[n * 2 + 2][1];
        }
    }

    int quaryRange(int n, int st, int ed, int l, int r) {
        if (lazy[n] != '0')
            propagation(n, st, ed);
        if (st > r || ed < l)
            return 0;
        else if (st >= l && ed <= r)
            return tree[n][1];
        else {
            int mid = (st + ed) >> 1;
            return quaryRange(n * 2 + 1, st, mid, l, r) + quaryRange(n * 2 + 2, mid + 1, ed, l, r);
        }
    }

    void solve(istream &cin, ostream &cout) {
        int T, testCases = 1;
        cin >> T;
        while (T--) {
            int t;
            cin >> t;
            while (t--) {
                int rep;
                string str;
                cin >> rep >> str;
                while (rep--)
                    s += str;
            }
            int n = sz(s);
            build(0, 0, n - 1);
            cout << "Case " << testCases++ << ":\n";
            int q;
            cin >> q;
            for (int i = 0, numOfQuary = 1; i < q; i++) {
                char type;
                int l, r;
                cin >> type >> l >> r;
                if (type == 'S')
                    cout << "Q" << numOfQuary++ << ": " << quaryRange(0, 0, n - 1, l, r) << el;
                else
                    updateRange(0, 0, n - 1, l, r, type);
            }
            init(n);
        }
    }
};