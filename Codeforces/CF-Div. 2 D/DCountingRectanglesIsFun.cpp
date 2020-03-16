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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;
#define el  '\n'
#define ll long long
#define sz(a) (int)(a).size()
template<typename T> using heap = priority_queue<T, vector<T>, less<T>>;
using ordered_set =  tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
const long long N = 42, OO = 0x3f3f3f3f, MOD = (long long) 1e9 + 7;
#define Rep(i, j, k) for (int i = j; i < k; i++)

char grid[N][N];
ll dp[N][N][N][N], cum[N][N];

bool allZeros(int i, int j, int k, int l) {
    return cum[k][l] - cum[i - 1][l] - cum[k][j - 1] + cum[i - 1][j - 1] == (k - i + 1) * (l - j + 1);
}

class DCountingRectanglesIsFun {
public:
    void solve(istream &cin, ostream &cout) {
        int n, m, q;
        cin >> n >> m >> q;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> grid[i][j];
                cum[i][j] = cum[i - 1][j] + cum[i][j - 1] - cum[i - 1][j - 1] + (grid[i][j] == '0');
            }
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                for (int k = i; k <= n; k++)
                    for (int l = j; l <= m; l++) {
                        dp[i][j][k][l] = dp[i][j][k - 1][l] + dp[i][j][k][l - 1] - dp[i][j][k - 1][l - 1];
                        for (int o = k; o >= i; o--)
                            for (int p = l; p >= j; p--)
                                dp[i][j][k][l] += allZeros(o, p, k, l);
                    }
        while (q--) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            cout << dp[a][b][c][d] << el;
        }
        memset(dp, 0, sizeof(dp));
        memset(cum, 0, sizeof(cum));
    }
};