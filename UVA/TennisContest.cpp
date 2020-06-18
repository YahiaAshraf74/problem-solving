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

int n;
double p, mem[50][26];

class TennisContest {
public:
    void init() {
        clr(mem,-1);
    }

    double solve(int played, int won) {
        if (won == n)
            return 1.0;
        if (played == 2 * n - 1)
            return 0.0;
        double &ret = mem[played][won];
        if (ret == ret)
            return ret;
        return ret = solve(played + 1, won + 1) * p + solve(played + 1, won) * (1.0 - p);
    }

    void solve(istream &cin, ostream &cout) {
        int T, testCases = 1;
        cin >> T;
        while (T--) {
            init();
            cin >> n >> p;
            cout << fixed << setprecision(2) << solve(0, 0) << el;
        }
        }
};