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

int a[N];

class MaximumKSums {
public:
    void init() {

    }

    void solve(istream &cin, ostream &cout) {
        init();
        int n, k;
        cin >> n >> k;
        ll sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum += (ll) a[i];
        }
        set<array<ll, 3>,greater<array<ll,3>>> s;
        s.insert({sum, 1, n});
        while (k-- && !s.empty()) {
            auto top = *s.begin();
            ll sum = top[0], l = top[1], r = top[2];
            s.erase(top);
            cout << sum << " \n"[k == 0];
            if (l != r) {
                s.insert({(ll) sum - a[l], l + 1, r});
                s.insert({(ll) sum - a[r], l, r - 1});
            }
        }

    }
};