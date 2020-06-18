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
const long long N = (int) 3e2 + 5, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

double dp[N][N][N];

class JSushi {
public:
    void init() {
        clr(dp,0);
    }

    void solve(istream &cin, ostream &cout) {
        init();
        int n;
        cin >> n;
        vector<int> cnt(4);
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            cnt[x]++;
        }
        for (int k = 0; k <= n; k++) {
            for (int j = 0; j + k <= n; j++) {
                for (int i = 0; i + j + k <= n; i++) {
                    if (i == 0 && j == 0 && k == 0) {
                        continue;
                    }
                    double wait = 1.0 * n / (i + j + k);
                    double pi = 1.0 * i / (i + j + k);
                    double pj = 1.0 * j / (i + j + k);
                    double pk = 1.0 * k / (i + j + k);
                    if (i != 0) {
                        dp[i][j][k] += pi * dp[i - 1][j][k];
                    }
                    if (j != 0) {
                        dp[i][j][k] += pj * dp[i + 1][j - 1][k];
                    }
                    if (k != 0) {
                        dp[i][j][k] += pk * dp[i][j + 1][k - 1];
                    }
                    dp[i][j][k] += wait;
                }
            }
        }
        cout << fixed << setprecision(10) << dp[cnt[1]][cnt[2]][cnt[3]] << el;
    }
};