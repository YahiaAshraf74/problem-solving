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

class CPlant {
public:
    void init() {

    }

    long long power(long long b, long long p, long long MOD = (long long) 1e9 + 7) {
        long long res = 1;
        b %= MOD;
        for (; p; p >>= 1LL) {
            if (p & 1)res = (res * b) % MOD;
            b = (b * b) % MOD;
        }
        return res % MOD;
    }


    void solve(istream &cin, ostream &cout) {
        init();
        ll n;
        cin >> n;
        if (n == 0) {
            cout << 1 << el;
        } else if (n == 1) {
            cout << 3 << el;
        } else if (n == 2) {
            cout << 10 << el;
        } else {
            cout << (power(2, 2 * n - 1) + power(2, n - 1)) % MOD << el;
        }
    }
};