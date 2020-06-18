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

class Tribles {
public:
    void init() {

    }

    void solve(istream &cin, ostream &cout) {
        int T, testCases = 1;
        cin >> T;
        while (T--) {
            int n, k, m;
            cin >> n >> k >> m;
            vector<double> p(n);
            for (int i = 0; i < n; i++)
                cin >> p[i];
            vector<double> dp(m + 1);
            dp[1] = p[0];
            for (int i = 2; i <= m; i++) {
                for (int j = 0; j < n; j++) {
                    dp[i] += p[j] * pow(dp[i - 1], j);
                }
            }
            cout << "Case #" << testCases++ << ": " << fixed << setprecision(7) << pow(dp[m], k) << el;
        }
    }
};