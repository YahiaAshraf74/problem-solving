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

class DPairOfTopics {
public:
    void init() {

    }

    void solve(istream &cin, ostream &cout) {
        init();
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a[i] -= x;
        }
        a[n] = OO;
        sort(a, a + n + 1);
        ll ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > 0) {
                ans += (ll)n-i-1;
            } else {
                int idx = upper_bound(a, a + n + 1, (-a[i])) - a;
                if (idx > i)
                    ans += (ll) n - idx;
            }
        }
        cout << ans << el;
    }
};