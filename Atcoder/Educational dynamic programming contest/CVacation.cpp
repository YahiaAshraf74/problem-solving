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

int a[N][3];
int dp[N][3];

class CVacation {
public:
    void init() {
        clr(dp, 0);
    }

    void solve(istream &cin, ostream &cout) {
        init();
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++)
                cin >> a[i][j];
        }
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < 3; k++) {
                for (int j = 0; j < 3; j++) {
                    if (k != j)
                        dp[i][j] = max(dp[i][j], dp[i - 1][k] + a[i][j]);
                }
            }
        }
        cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    }
};