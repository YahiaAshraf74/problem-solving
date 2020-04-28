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
#define ull unsigned long long
#define clr(a, b)memset(a,b,sizeof(a))
#define sz(a) (int)(a).size()
const long long N = (int) 2e5 + 74, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

ull dp[25][152];

class DiceThrowing {
public:
    void init() {

    }

    void solve(istream &cin, ostream &cout) {
        init();
        int n, x;
        dp[0][0] = 1;
        for (int i = 1; i <= 24; i++) {
            dp[i][0] = dp[i - 1][0] * 6;
        }
        for (int i = 1; i <= 24; i++) {
            for (int s = 1; s <= 150; s++) {
                for (int k = 1; k <= 6; k++) {
                    if (s > k)
                        dp[i][s] += dp[i - 1][s - k];
                    else
                        dp[i][s] += dp[i - 1][0];
                }
            }
        }
        while (cin >> n >> x) {
            if (!n && !x)
                break;
            ull num = dp[n][x], dem = dp[n][0], g = __gcd(num, dem);
            num /= g, dem /= g;
            if (dem == 1) {
                cout << num << el;
            } else {
                cout << num << "/" << dem << el;
            }
        }
    }
};