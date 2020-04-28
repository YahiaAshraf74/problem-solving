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
const long long N = 1002, OO = (ll) 1e18, MOD = (int) 1e9 + 7;

ll sumRow[N], sumCol[N];

class DGuessThatCar {
public:
    void init() {
        clr(sumRow, 0), clr(sumCol, 0);
    }

    void solve(istream &cin, ostream &cout) {
        init();
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                sumRow[i] += (ll) x;
                sumCol[j] += (ll) x;
            }
        }
        int minX = 1005;
        ll mnX = OO;
        for (int i = 0; i <= n; i++) {
            ll res = 0;
            for (int ii = 0; ii < n; ii++)
                res += (ll) 4 * sumRow[ii] * (1 + 2 * ii - 2 * i) * (1 + 2 * ii - 2 * i);
            if (res < mnX)
                mnX = res, minX = i;
        }
        int minY = 1005;
        ll mnY = OO;
        for (int j = 0; j <= m; j++) {
            ll res = 0;
            for (int jj = 0; jj < m; jj++)
                res += (ll) 4 * sumCol[jj] * (1 + 2 * jj - 2 * j) * (1 + 2 * jj - 2 * j);
            if (res < mnY)
                mnY = res, minY = j;
        }
        cout << mnX + mnY << el;
        cout << minX << ' ' << minY << el;
    }
};