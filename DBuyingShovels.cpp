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
const long long N = (int) 2e5 + 74, OO = 0x3f3f3f3f, MOD = (int) 1e9 + 7;

class DBuyingShovels {
public:
    void solve(istream &cin, ostream &cout) {
        int T, testCases = 1;
        cin >> T;
        while (T--) {
            ll n, k;
            cin >> n >> k;
            if (k >= n) {
                cout << 1 << el;
                continue;
            }
            ll ans = n;
            for (ll i = 2; i * i <= n; i++) {
                if (n % i == 0 && i <= k) {
                    ans = min(ans, n / i);
                }
                ll j = n / i;
                if (n % j == 0 && j <= k) {
                    ans = min(ans, n/j);
                }
            }
            cout << ans << el;
        }
    }
};