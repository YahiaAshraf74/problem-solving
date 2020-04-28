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
const long long N = 2e5 + 1, OO = 0x3f3f3f3f, MOD = (long long) 1e9 + 7;

int a[N];
int tree[N * 4];

class Potentiometers {
public:
    void init() {
        clr(tree, 0);
    }

    void build(int n, int st, int ed) {
        if (st == ed)
            tree[n] = a[st];
        else {
            build(n * 2 + 1, st, (st + ed) / 2);
            build(n * 2 + 2, (st + ed) / 2 + 1, ed);
            tree[n] = tree[n * 2 + 1] + tree[n * 2 + 2];
        }
    }

    void update(int n, int st, int ed, int idx, int val) {
        if (st == ed) {
            a[idx] = val;
            tree[n] = val;
        } else {
            if (idx >= st && idx <= (st + ed) / 2)
                update(n * 2 + 1, st, (st + ed) / 2, idx, val);
            else
                update(n * 2 + 2, (st + ed) / 2 + 1, ed, idx, val);
            tree[n] = tree[n * 2 + 1] + tree[n * 2 + 2];
        }
    }

    int quary(int n, int st, int ed, int l, int r) {
        if (r < st || l > ed)
            return 0;
        else if (st >= l && ed <= r)
            return tree[n];
        else
            return quary(n * 2 + 1, st, (st + ed) / 2, l, r) + quary(n * 2 + 2, (st + ed) / 2 + 1, ed, l, r);
    }

    void solve(istream &cin, ostream &cout) {
        int n, testCases = 1;
        while (cin >> n) {
            if (!n)
                break;
            init();
            for (int i = 0; i < n; i++)
                cin >> a[i];
            build(0, 0, n - 1);
            string type;
            cout << "Case " << testCases++ << ":\n";
            while (cin >> type) {
                if (type == "END")
                    break;
                else if (type == "S") {
                    int idx, val;
                    cin >> idx >> val;
                    update(0, 0, n - 1, idx - 1, val);
                } else {
                    int l, r;
                    cin >> l >> r;
                    cout << quary(0, 0, n - 1, l - 1, r - 1) << el;
                }
            }
        }
    }
};