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
const long long N = 2e5 + 74, OO = 0x3f3f3f3f, MOD = (long long) 1e9 + 7;

class DEhabTheXorcist {
public:
    void solve(istream &cin, ostream &cout) {
        ll n, m;
        cin >> n >> m;
        if (m < n || n % 2 != m % 2)
            cout << -1 << el;
        else if (n == m && n == 0)
            cout << 0 << el;
        else if (n == m)
            cout << 1 << el << n << el;
        else {
            ll x = (m - n) / 2;
            if (n & x)
                cout << 3 << el << n << ' ' << x << ' ' << x << el;
            else
                cout << 2 << el << (n ^ x) << ' ' << x << el;
        }
    }
};
