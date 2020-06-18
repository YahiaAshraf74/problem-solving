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

class CLCMChallenge {
public:
    void solve(istream &cin, ostream &cout) {
        ll n;
        cin >> n;
        if (n < 3) {
            cout << n << el;
            return;
        }
        ll lcm = (n * (n - 1)) / __gcd(n, n - 1);
        ll mx = (n - 1) * (n - 2) * (n - 3);
        for (ll i = n - 2; i >= 1; i--) {
            mx = max(mx, (lcm * i) / __gcd(lcm, i));
        }
        cout << mx << el;
    }
};