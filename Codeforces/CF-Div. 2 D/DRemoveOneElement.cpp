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
int l[N], r[N];

class DRemoveOneElement {
public:
    void init() {

    }

    void solve(istream &cin, ostream &cout) {
        init();
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int ans = 0;
        l[0] = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] > a[i - 1]) {
                l[i] = l[i - 1] + 1;
                ans = max(ans, l[i]);
            } else
                l[i] = 1;
        }
        r[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] < a[i + 1]) {
                r[i] = r[i + 1] + 1;
                ans = max(ans,r[i]);
            } else
                r[i] = 1;
        }
        for (int i = n - 1; i > 0; i--) {
            if (a[i + 1] > a[i - 1])
                ans = max(ans, l[i - 1] + r[i + 1]);
        }
        cout << ans << el;
    }
};