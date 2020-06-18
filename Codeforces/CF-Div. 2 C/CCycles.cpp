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
#include <numeric>
#include <assert.h>

using namespace std;
#define el  '\n'
#define ll long long
#define clr(a, b)memset(a,b,sizeof(a))
#define sz(a) (int)(a).size()
const long long N = (int) 1e2 + 2, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

int vis[N][N];

class CCycles {
public:
    void init() {

    }

    void solve(istream &cin, ostream &cout) {
        init();
        int k;
        cin >> k;
        for (int i = 1; i <= 100; ++i) {
            for (int j = 1; j < i; ++j) {
                int nx = 0;
                for (int p = 1; p <= 100; ++p)
                    nx += (vis[i][p] && vis[p][j]);
                if (nx > k)
                    continue;
                k -= nx;
                vis[i][j] = vis[j][i] = true;
            }
        }
        cout << 100 << el;
        for (int i = 1; i <= 100; ++i) {
            for (int j = 1; j <= 100; ++j)
                cout << vis[i][j];
            cout << el;
        }
    }
};