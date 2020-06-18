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
const long long N = 102, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

//ll dp[N][(int) 1e5 + 2];
ll dp[(int)1e5+2];
class DKnapsack1 {
public:
    void init() {
        clr(dp, 0);
    }

    void solve(istream &cin, ostream &cout) {
        init();
//        int n, totW;
//        cin >> n >> totW;
//        for (int i = 0; i < n; i++) {
//            int w, v;
//            cin >> w >> v;
//            for (int curW = 0; curW <= totW; curW++) {
//                if (i - 1 < 0) {
//                    dp[i][curW] = (curW - w >= 0) ? v : 0;
//                    continue;
//                }
//                if (curW - w >= 0)
//                    dp[i][curW] = max(dp[i - 1][curW], dp[i - 1][curW - w] + v);
//                else
//                    dp[i][curW] = dp[i - 1][curW];
//            }
//        }
//        cout << dp[n - 1][totW] << el;
        int n, totW;
        cin >> n >> totW;
        for (int i = 0; i < n; i++) {
            int w, v;
            cin >> w >> v;
            for (int curW = totW; curW >= w; curW--)
                dp[curW] = max(dp[curW], dp[curW - w] + v);
        }
        cout << *max_element(dp, dp + totW + 1) << el;
    }
};
