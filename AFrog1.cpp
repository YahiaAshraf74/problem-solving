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
const long long N = (int) 2e5 + 74, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;


class AFrog1 {
public:
    void init() {
    }

    void solve(istream &cin, ostream &cout) {
        init();
        int n;
        cin >> n;
        int dp[3] = {}, h[3] = {};
        int dp0 = 0, dp1 = 0, ans = 0;
        int stone0 = 0, stone1 = 0, curStone;
        for (int i = 0; i < n; i++) {
            int ii = i % 3;
            int j = ((i - 1) % 3 + 3) % 3;
            int k = ((i - 2) % 3 + 3) % 3;
            cin >> h[ii];
            if (i == 0)
                continue;
            else if (i == 1) {
                dp[ii] = abs(h[ii] - h[j]);
                continue;
            }
            dp[ii] = min(dp[j] + abs(h[ii] - h[j]), dp[k] + abs(h[ii] - h[k]));
        }
        cout << dp[(n - 1) % 3] << el;
    }
};