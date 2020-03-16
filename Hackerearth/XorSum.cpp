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
const long long N = 2e5 + 74, LN = 41, OO = 0x3f3f3f3f, MOD = (long long) 1e9 + 7;

ll a[N];
int cum[LN][N];

long long power(long long b, long long p, long long MOD = (long long) 1e9 + 7) {
    long long res = 1;
    b %= MOD;
    for (; p; p >>= 1LL) {
        if (p & 1)res = (res * b) % MOD;
        b = (b * b) % MOD;
    }
    return res;
}

const int inv_6 = power(6, MOD - 2), inv_2 = power(2, MOD - 2);

ll nC3(int n) {
    if (n < 3)
        return 0;
    return (((n * (n - 1)) % MOD * (n - 2)) % MOD * inv_6) % MOD;
}

ll nC2(int n) {
    if (n < 2)
        return 0;
    return ((n * (n - 1)) % MOD * inv_2) % MOD;
}

class XorSum {
public:
    void solve(istream &cin, ostream &cout) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int j = 0; j < LN; j++) {
            for (int i = 1; i <= n; i++)
                cum[j][i] = cum[j][i - 1] + ((a[i] >> j) & 1);
        }
        int q, two;
        cin >> q >> two;
        for (int i = 0; i < q; i++) {
            int l, r;
            cin >> l >> r;
            ll res = 0, size = r - l + 1;
            for (int j = 0; j < LN; j++) {
                ll numOfOnes = (cum[j][r] - cum[j][l - 1]), numOfZeros = size - numOfOnes;
                ll ans = (numOfOnes * nC2(numOfZeros)) % MOD, ans2 = nC3(numOfOnes);
                res = (res + (((1ll << j) % MOD) * ((ans + ans2)) % MOD) % MOD) % MOD;
            }
            cout << res << el;
        }
    }
};