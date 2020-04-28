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
const long long N = (int) 1e5 + 3, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

int n, m, k;
int a[N][5];
int tree[N * 4][5];

class DR2D2AndDroidArmy {
public:
    void init() {
        clr(tree, 0);
    }

    void build(int n, int st, int ed) {
        if (st == ed) {
            for (int i = 0; i < m; i++)
                tree[n][i] = a[st][i];
            return;
        }
        int mid = (st + ed) >> 1;
        build(n * 2 + 1, st, mid);
        build(n * 2 + 2, mid + 1, ed);
        for (int i = 0; i < m; i++)
            tree[n][i] = max(tree[n * 2 + 1][i], tree[n * 2 + 2][i]);
    }

    int quary(int n, int st, int ed, int l, int r, int t) {
        if (ed < l || st > r)
            return 0;
        else if (st >= l && ed <= r) {
            return tree[n][t];
        } else {
            int mid = (st + ed) >> 1;
            return max(quary(n * 2 + 1, st, mid, l, r, t), quary(n * 2 + 2, mid + 1, ed, l, r, t));
        }
    }

    int quaryAll(int l, int r) {
        int sum = 0;
        for (int i = 0; i < m; i++)
            sum += quary(0, 0, n - 1, l, r, i);
        return sum;
    }

    void solve(istream &cin, ostream &cout) {
        init();
        cin >> n >> m >> k;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        build(0, 0, n - 1);
        int len = 0, mx = 0, mxL = 0, mxR = 0;
        for (int i = 0, j = 0; j < n;) {
            if (quaryAll(i, j) <= k) {
                if (mx < j - i + 1)
                    mxL = i, mxR = j, mx = j - i + 1;
                j++;
            } else {
                if (j > i)
                    i++;
                else
                    j++,i++;
            }
        }
        for (int i = 0; i < m; i++) {
            if(mx)
                cout << quary(0, 0, n - 1, mxL, mxR, i) << ' ';
            else
                cout << 0 << ' ';
        }
    }
};