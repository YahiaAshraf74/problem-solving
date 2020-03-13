#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include<stack>
#include <complex>
#include <string>
#include <bitset>
#include <stdio.h>
#include <string.h>
#include<fstream>
#include <iomanip>

using namespace std;
#define el    '\n'
#define ll long long
#define clr(a, b)memset(a,b,sizeof(a))
#define all(v)  ((v).begin()),((v).end())
const int N = 2e5 + 74;
const ll OO = (ll) 1e18;

ll gcd(ll a, ll b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}

ll p[N];
ll x, b, y, a, k;

ll can(ll m) {
    ll sum = 0;
    ll lm = lcm(b, a);
    int j = 1;
    for (ll i = lm; i <= m; i += lm) {
        sum += p[j] * (x + y);
        j++;
    }
    for (int i = b; i <= m; i += b) {
        if (i % b == 0 && i % a != 0) {
            sum += p[j] * x;
            j++;
        }
    }
    for (int i = a; i <= m; i += a) {
        if (i % a == 0 && i % b != 0) {
            sum += p[j] * y;
            j++;
        }
    }
    return sum;
}

class CSaveTheNature {
public:
    void solve(istream &cin, ostream &cout) {
        int q;
        cin >> q;
        while (q--) {
            int n;
            cin >> n;
            for (int i = 1; i <= n; i++)
                cin >> p[i], p[i] /= 100;
            sort(p + 1, p + n + 1, greater<ll>());
            cin >> x >> b >> y >> a >> k;
            if (x < y)
                swap(x, y), swap(b, a);
            ll st = 1, ed = n;
            ll ans = OO;
            while (st <= ed) {
                ll mid = (st + ed) / 2;
                if (can(mid) >= k) {
                    ans = min(ans, mid);
                    ed = mid - 1;
                } else {
                    st = mid + 1;
                }
            }
            if (ans != OO) {
                cout << ans << el;
            } else {
                cout << -1 << el;
            }
        }
    }
};