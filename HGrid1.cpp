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
const long long N = (int) 1e3 + 3, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

char grid[N][N];
int dp[N][N];

class HGrid1 {
public:
    void init() {
        clr(dp, 0);
    }

    void solve(istream &cin, ostream &cout) {
        init();
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> grid[i][j];
            }
        }
        dp[1][1] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if(i == 1 && j == 1)
                    continue;
                if (grid[i][j] == '#')
                    continue;
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }
        }
        cout << dp[n][m] << el;
    }
};