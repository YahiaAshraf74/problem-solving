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

int n;
ll k;
int a[N];
ll cum[N];

class ShootingTheBalloons {
public:
    void init() {

    }

    ll query(int l, int r) {
        ll left = l == 0 ? 0 : cum[l - 1];
        ll right = cum[r];
        return right - left;
    }

    ll getIdx(ll k2) {
        ll idx = 0; // number of subarrays before the k2 value
        for (int i = 0; i < n; i++) {
            ll low = i, high = n - 1;
            ll j = 0;
            while (low <= high) {
                ll mid = low + ((high - low) >> 1);
                if (query(i, mid) <= k2) {
                    j = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            idx += max(0LL, j - i + 1);
        }
        return idx;
    }

    void solve(istream &cin, ostream &cout) {
        init();
        cin >> n >> k;
        cin >> a[0];
        cum[0] = a[0];
        for (int i = 1; i < n; ++i) {
            cin >> a[i];
            cum[i] = (ll) cum[i - 1] + a[i];
        }
        ll ans = 0;
        ll low = 0, high = cum[n - 1];
        while (low <= high) {
            ll mid = low + ((high - low) >> 1);
            if (getIdx(mid) >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << el;
    }
};