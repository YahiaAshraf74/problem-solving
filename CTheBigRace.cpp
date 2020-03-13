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
#define el    '\n'
#define ll long long
#define clr(a, b)memset(a,b,sizeof(a))
#define all(v)((v).begin()),((v).end())
#define write(v) freopen(v,"w",stdout)
const int N = 5e3 + 74, OO = 0x3f3f3f3f;

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

bool isOverflow(ll a, ll b) {
    unsigned ll res = a * b;
    if (a != 0 && res / a != b)
        return true;
    return false;
}

class CTheBigRace {
public:
    void solve(istream &cin, ostream &cout) {
        ll t, b, w;
        cin >> t >> b >> w;
        if (b == w || min(b, w) > t) {
            cout << "1/1";
            return;
        }
        ll g = gcd(b, w);
        ll lcm = w / g;
        ll ans = 0;
        if (isOverflow(b, lcm)){
            ans = min(b, w) - 1;
        } else {
            lcm *= b;
            ans = (t / lcm - 1) * min(w, b);
            ans += min(w, b) - 1;
            ans += min(t - (t / lcm) * lcm + 1, min(w, b));
        }
        g = gcd(ans, t);
        cout << ans/g << '/' << t/g << el;
    }
};