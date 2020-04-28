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
#include <numeric>

using namespace std;
#define el  '\n'
#define ll long long
#define clr(a, b)memset(a,b,sizeof(a))
#define sz(a) (int)(a).size()
const long long N = (int) 3e3 + 2, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;


class ICoins {
public:
    void init() {
    }

    void solve(istream &cin, ostream &cout) {
        init();
        int n;
        cin >> n;
        vector<double> heads(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> heads[i];
        }
        vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0.0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
            dp[i][0] = dp[i - 1][0] * (1.0 - heads[i]);
        for (int j = 1; j <= n; j++)
            dp[0][j] = 0.0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i][j] = dp[i - 1][j - 1] * heads[i] + dp[i - 1][j] * (1.0 - heads[i]);
            }
        }
        double sum = 0.0;
        for (int heads = 0; heads <= n; heads++) {
            int tails = n - heads;
            if (heads > tails)
                sum += dp[n][heads];
        }
        cout << fixed << setprecision(10) << sum;

    }
};