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
const long long N = 1e5 + 74, OO = 0x3f3f3f3f, MOD = 998244353;

int f[N], a[N];

long long power(long long b, long long p, long long MOD = 998244353) {
    long long res = 1;
    b %= MOD;
    for (; p; p >>= 1LL) {
        if (p & 1)res = (res * b) % MOD;
        b = (b * b) % MOD;
    }
    return res % MOD;
}

class BCountingOfTrees {
public:
    void solve(istream &cin, ostream &cout) {
        int n;
        cin >> n;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            f[a[i]]++;
            mx = max(mx, a[i]);
        }
        if (f[0] != 1 || a[0] != 0)
            return (void) (cout << 0 << el);
        int ans = 1;
        for (int i = 1; i <= mx; i++) {
            if(!f[i])
                return (void) (cout << 0 << el);
            ans = (ans * power(f[i - 1], f[i])) % MOD;
        }
        cout << ans << el;
        clr(f, 0);
    }
};